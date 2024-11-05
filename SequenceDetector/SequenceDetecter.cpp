#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <set>

using namespace std;

struct Transition {
    char present_state;
    char next_state;
    int input;
    int output;
};

int main() {
    vector<Transition> transitions;
    unordered_map<char, vector<pair<int, char>>> state_map; // Maps present state to (input, next state)
    set<char> visited_states; // To keep track of visited states
    char initial_state = '\0';
    char final_state = '\0';
    string sequence = "";

    // Read input
    string line;
    while (getline(cin, line) && !line.empty()) {
        Transition t;
        istringstream iss(line);
        iss >> t.present_state >> t.next_state >> t.input >> t.output;
        transitions.push_back(t);
        state_map[t.present_state].push_back({t.input, t.next_state});
        
        if (initial_state == '\0') {
            initial_state = t.present_state; // Set initial state
        }
        final_state = t.next_state; // Update final state
    }

    // Generate the sequence
    char current_state = initial_state;
    while (true) {
        bool found = false;
        for (const auto& t : transitions) {
            if (t.present_state == current_state) {
                sequence += to_string(t.input);
                visited_states.insert(current_state); // Mark state as visited
                current_state = t.next_state;
                found = true;
                break; // Move to the next state
            }
        }
        if (!found) break; // No more transitions found
    }

    // Check if the sequence length is valid
    if (sequence.length() < 2 || sequence.length() > 10) {
        cout << "Invalid sequence length." << endl;
        return 1; // Exit with error
    }

    // Check if all states are visited and transitions equal to states
    bool all_states_visited = (visited_states.size() == state_map.size());
    bool valid_transitions = (transitions.size() == visited_states.size());

    // Check if the detector is non-overlapping
    bool non_overlapping = false;
    for (const auto& t : transitions) {
        if (t.present_state == final_state && t.next_state == initial_state && t.output == 1) {
            non_overlapping = true;
            break;
        }
    }

    // Output the results
    cout << sequence << endl;
    if (non_overlapping) {
        cout << "Non Overlapping Sequence Detector" << endl;
    } else {
        cout << "Overlapping Sequence Detector" << endl;
    }

    // Check if all constraints are met
    if (!all_states_visited || !valid_transitions) {
        cout << "Constraints not met." << endl;
    }

    return 0;
}
