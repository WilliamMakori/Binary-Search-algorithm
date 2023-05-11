//
//  main.cpp
//  Binary Search practice
//
//  Created by Makori Chacha on 2023-05-04.
//
//
//Suppose you have an array arr of n integers that are sorted in ascending order. You also have an integer k. Write a function binary_search(arr, k) that returns the index of the first occurrence of k in arr, or -1 if k is not present in arr.
//
//For example, given the array arr = [1, 2, 2, 3, 4, 4, 4, 5, 6, 6] and the integer k = 4, the function should return the index 4, which is the first occurrence of k in arr.
//
//Here's the twist: your implementation of binary_search must have a time complexity of O(log n) or better. In other words, you cannot simply use a linear search algorithm to solve this problem.
// Good luck!
#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;

void bubbleSort (int arr [], int n){
    // Bubble sort.
    for (int i = 0; i < n - 1; i++) {
            // Last i elements are already in place
            for (int j = 0; j < n - i - 1; j++) {
                // Swap adjacent elements if they are in the wrong order
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
}
bool binarySearch(int x[],int searchValue, int size){
    
    // bubbleSort(x, size);
    
    int low = 0;
    int high = size - 1;
    int mid = (high+low)/2;
//    for( int k = mid; mid<size && mid > 0;mid){
//
//    }
    // The function needs to keep running as long as low <= high
    // As long as the value of low doesn't exceed the value of high i.e the array hasn't been exhausted.
     
    while(low <= high){
        
        if (searchValue == x[mid])
            return true;
        
        else if (x[mid] > searchValue){
            high = mid - 1;
            mid = (high+low)/2;
        }
        else{
            // Exclude the middle index that is out of range
            low = mid + 1;
            mid = (high+low)/2;
        }
    }
    return false;
    
}
void dfs(vector<vector<int>>& graph, int start_node) {
    
    vector<bool> visited(graph.size(), false);   // initialize all nodes as unvisited
    
    stack<int> s;
    
    s.push(start_node);   // add the start node to the stack

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        if (!visited[node]) {
            visited[node] = true;   // mark node as visited
            cout << node << " ";    // process the node (in this case, print its value)
            for (int i = 0; i < graph[node].size(); i++) {
                int neighbor = graph[node][i];
                if (!visited[neighbor]) {
                    s.push(neighbor);   // add unvisited neighbors to the stack
                }
            }
        }
    }
   
    
}

int main(int argc, const char * argv[]) {
    
    // Example graph
    // A vector is just an array with pre-written functionality
    // A vector of vectors,
        vector<vector<int>> graph = {
            {1, 2},
            {0, 3, 4},
            {0, 4},
            {1},
            {1, 2}
        };

        // Perform DFS starting from node 0
        cout << "DFS traversal starting from node 0: ";
        dfs(graph, 0);
        cout << endl;

        // Perform DFS starting from node 3
        cout << "DFS traversal starting from node 3: ";
        dfs(graph, 3);
        cout << endl;
   
    system("Pause");
    return 0;
    
}
