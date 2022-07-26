#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
const double pi=acos(-1.0);
#define ll long long
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<vector<int>> VII;
typedef vector<string> VS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define ff(a,b) for(int i=a;i<b;i++)
#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define ff1(pass) for(long long int i=n-2;i>=0;--i)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

class Solution {
public:
    //check my given island is closed or not
    bool dfs(vector<vector<int>>&grid,int i,int j,int m,int n)
{
    if(i<0 or i>=m or j<0 or j>=n){return false;}
    
    if(grid[i][j]==1 or grid[i][j]==2){return true;}//it work on 1 is visited
        
        //making a grid as visited
        grid[i][j]=2;
        
        //4 directions
        bool top=dfs(grid,i-1,j,m,n);
        bool down=dfs(grid,i+1,j,m,n);
        bool left=dfs(grid,i,j-1,m,n);
        bool right=dfs(grid,i,j+1,m,n);
        
    return top and down and left and right;
}
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        // f1(i,1,n-1)
        for(int i=1;i<m-1;++i)
        {
            // f1(j,1,m-1)
            for(int j=1;j<n-1;++j)
            {
                if(grid[i][j]==0)
                {
                    //if dfs call is again true then increse the count
                    if(dfs(grid,i,j,m,n))
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};