#include <iostream>
using namespace std;

class Solution {
public:
    // Comparator order: predefined sequence to match
    const string order = "!#$%&*?@^";

    // Helper function to partition the array
    int partition(char arr[], int low, int high, char pivot) {
        int i = low;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                swap(arr[i], arr[j]);
                i++;
            } else if (arr[j] == pivot) {
                swap(arr[j], arr[high]);
                j--;
            }
        }
        swap(arr[i], arr[high]);
        return i;
    }

    // Match nuts and bolts using partitioning
    void matchPairsUtil(char nuts[], char bolts[], int low, int high) {
        if (low < high) {
            // Use nuts[low] as pivot to partition bolts
            char pivot = nuts[low];
            int partitionIndex = partition(bolts, low, high, pivot);

            // Use the matched bolt as pivot to partition nuts
            partition(nuts, low, high, bolts[partitionIndex]);

            // Recursive matching for left and right partitions
            matchPairsUtil(nuts, bolts, low, partitionIndex - 1);
            matchPairsUtil(nuts, bolts, partitionIndex + 1, high);
        }
    }

    void matchPairs(int n, char nuts[], char bolts[]) {
        matchPairsUtil(nuts, bolts, 0, n - 1);
        cout << "Matched nuts: ";
        for (int i = 0; i < n; i++) cout << nuts[i] << " ";
        cout << "\nMatched bolts: ";
        for (int i = 0; i < n; i++) cout << bolts[i] << " ";
        cout << endl;
    }
};

int main(){
    char nuts[] = {'@', '%', '$', '#', '^'}, bolts[] = {'%', '@', '#', '$' ,'^'};
    int n=5;
    Solution s;
    s.matchPairs(n,nuts, bolts);

    return 0;

}