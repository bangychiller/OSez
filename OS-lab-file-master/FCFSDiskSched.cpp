#include <iostream>
using namespace std;
  
void FCFS(int arr[], int head,int size)
{
    int seek_count = 0;
    int distance, cur_track;
  
    for (int i = 0; i < size; i++) {
        cur_track = arr[i];
        distance = abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }
  
    cout << "Total number of seek operations = "<< seek_count << endl;
    cout << "Seek Sequence is: ";
  
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
  
int main()
{
    int size = 8;
    int arr[size] = { 176, 79, 34, 60, 92, 11, 41, 114 };
    int head = 50;
  
    FCFS(arr, head,size);
  
    return 0;
}