class NumberContainers {
public:
    // Constructor
    // Initializes an empty data structure to store number-index mappings.
    NumberContainers() {}

    /**
     * Updates the mapping of an index to a number.
     * If the index already exists, it removes the previous number from the mapping.
     * Then, it assigns the new number to the given index.
     *
     * @param index The position where the number is to be stored.
     * @param number The value to be stored at the given index.
     */
    void change(int index, int number) {
        // If the index is already mapped to a number, update the mappings
        if (indexToNumbers.find(index) != indexToNumbers.end()) {
            int previousNumber = indexToNumbers[index];

            // Remove the index from the set of indices associated with the previous number
            numberToIndices[previousNumber].erase(index);

            // If the previous number is no longer mapped to any index, remove it from the map
            if (numberToIndices[previousNumber].empty()) {
                numberToIndices.erase(previousNumber);
            }
        }

        // Update the index-to-number mapping
        indexToNumbers[index] = number;

        // Insert the index into the set associated with the new number
        numberToIndices[number].insert(index);
    }

    /**
     * Finds and returns the smallest index associated with a given number.
     *
     * @param number The number to search for.
     * @return The smallest index containing the number, or -1 if not found.
     */
    int find(int number) {
        // Check if the number exists in the mapping
        if (numberToIndices.find(number) != numberToIndices.end()) {
            // Since the indices are stored in a sorted set, return the smallest index
            return *numberToIndices[number].begin();
        }
        // Return -1 if the number is not present
        return -1;
    }

private:
    // Stores the mapping of each number to a sorted set of indices where it appears.
    unordered_map<int, set<int>> numberToIndices;

    // Stores the mapping of each index to its associated number.
    unordered_map<int, int> indexToNumbers;
};

/**
 * Example Usage:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index, number); // Assigns a number to an index.
 * int param_2 = obj->find(number); // Retrieves the smallest index containing the number.
 */
