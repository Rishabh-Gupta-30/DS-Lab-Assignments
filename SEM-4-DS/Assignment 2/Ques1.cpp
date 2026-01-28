#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void MaxNumOfActivities(vector<vector<int>>& pro){
    if (pro.empty()) {
    cout << endl <<0;
    return;
    }
    sort(pro.begin(),pro.end(),[](const vector<int>& a,const vector<int>& b){
       return a[1]<b[1]; 
    });
    int count = 1;
    int LastEnd = pro[0][1];
    for(int i=1;i<pro.size();i++){
        if(pro[i][0]>=LastEnd){
            count++;
            LastEnd = pro[i][1];
        }
    }
    cout<<endl<<"Total Number of Activities that will be performed : "<<count;
    return;
}
int main() {
    int N;
    vector<vector<int>> pro;
    cout<<"enter number of total elements: ";
    cin>>N;
    int start[N];
    int end[N];
    cout<<endl<<"enter start time of all processes: ";
    for(int i=0;i<N;i++){
        cin>>start[i];
    }
    cout<<endl<<"enter end time of all processes: ";
    for(int i=0;i<N;i++){
        cin>>end[i];
    }
    for(int i=0;i<N;i++){
        pro.push_back({start[i], end[i]});
    }
    MaxNumOfActivities(pro);
    return 0;
}
