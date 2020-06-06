#include "route_planner.h"
#include <algorithm>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y): m_Model(model) {
    // Convert inputs to percentage:
    start_x *= 0.01;
    start_y *= 0.01;
    end_x *= 0.01;
    end_y *= 0.01;

    this->start_node = &model.FindClosestNode(start_x, start_y);
    this->end_node = &model.FindClosestNode(end_x, end_y);
}

float RoutePlanner::CalculateHValue(RouteModel::Node const *node) {
    return node->distance(*this->end_node);
}

void RoutePlanner::AddNeighbors(RouteModel::Node *current_node) {
    current_node->FindNeighbors();
    for(auto neighbor: current_node->neighbors) {
        neighbor->h_value = CalculateHValue(neighbor);
        neighbor->g_value = current_node->g_value + current_node->distance(*neighbor);
        neighbor->parent = current_node;
        this->open_list.push_back(neighbor);
        neighbor->visited = true;
    }
}

RouteModel::Node *RoutePlanner::NextNode() {
    std::sort(open_list.begin(), open_list.end(), [](const auto & _1st, const auto & _2nd) {
		return (_1st->h_value + _1st->g_value) < (_2nd->h_value + _2nd->g_value);
	});
  
    RouteModel::Node* lowest = open_list.front();
	open_list.erase(open_list.begin());
  
    return lowest;
}

std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node) {
   // Create path_found vector
    distance = 0.0f;
    std::vector<RouteModel::Node> path_found;
  
  	while(current_node->parent != nullptr) {
      path_found.insert(path_found.begin(), *current_node);
      distance += current_node->distance(*current_node->parent);
      current_node = current_node->parent;
  	}
  
  	path_found.insert(path_found.begin(), *current_node);

    distance *= m_Model.MetricScale(); // Multiply the distance by the scale of the map to get meters.
    return path_found;
}

void RoutePlanner::AStarSearch() {
    RouteModel::Node *current_node = nullptr;
	  
    current_node = start_node;
  	current_node->visited=true; 
    while (current_node != end_node) {
        AddNeighbors(current_node);
        current_node = NextNode();
    }

    m_Model.path = ConstructFinalPath(current_node);
}