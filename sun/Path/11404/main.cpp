//
//  main.cpp
//  11404
//
//  Created by Sun on 2023/07/29.
//

#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int main(int argc, const char * argv[]) {

    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> d(n, vector<int>(n,INF));
    for (int i = 0; i < n; i++)
        d[i][i] = 0;

    // Initialize
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        d[a-1][b-1] = min(d[a-1][b-1], c);
    }
    
    // Update table (Floyd-Warshall)
    for (int k = 0; k < n; k++)
        for (int a = 0; a < n; a++)
            for (int b = 0; b < n; b++)
                d[a][b] = min(d[a][b], d[a][k] + d[k][b]);
    
    // Result
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << (d[i][j] == INF ? 0 : d[i][j]) << " ";
        cout << endl;
    }
    
    return 0;
}
