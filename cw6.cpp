#include<iostream>
using namespace std;

void createGraph(int v,int u, int p){
    int graph[100][100];
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            cout << i << " has any connection with " << j << " ?"<< endl;
            cin >> graph[i][j];
        }
    }
    // for(int i=1;i<=v;i++){
    //     for(int j=1;j<=v;j++){
    //         cout << i << " -> " << j << " = "<< graph[i][j] << " " << endl;
    //     }
    // }
    for(int i=1;i<=v;i++){
        if(i==u)
        cout << i << " -> ";
        for(int j=1;j<=v;j++){
            if(graph[i][j]!=0){
                if(i==u && j==p)
                cout << "Yes the path exists from " << i << " -> " << j;
            }
            
        }cout << endl;
    }

    int k=0,arr[100],arr2[100],t=0;
    for(int i=1;i<=v;i++){
        if(i==u)
        //cout << i << " -> ";
        for(int j=1;j<=v;j++){
            if(graph[i][j]!=0){
                if(i==p){
                    arr[k] = j;
                    k++;
                }
                if(i==u){
                    arr[t] = j;
                    t++;
                }
            }
            
        }//cout << endl;
    }
    for(int i=0;i<k;i++)cout<<arr[i] << " ";
    cout << endl;
    for(int i=0;i<t;i++)cout<<arr2[i] << " ";
}
int main(){
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;
    int u,p;
    cout << "Enter the value of u & p: " << endl;
    cin >> u >> p;
    createGraph(v,u,p);

}