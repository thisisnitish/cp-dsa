/*
Leetcode Question 841. Keys and Rooms
https://leetcode.com/problems/keys-and-rooms/
*/

/*
The crux of the problem is, it asks us to visit all the rooms or we can say visit
all the nodes. But there is catch here, you can't visit all the rooms because all
rooms are closed except 0.

So, you can visit 0 and then get the keys from there for the next rooms and unlock
them. Or, we can say, get the adjacent nodes and visit them one by one.

We can use DFS traversal for this because this is a simple DFS traversal problem.
Start from the src node 0 and take dfs call and visit the graph and while visiting
mark the node visited. If every node is visited return true else return false.
*/
class Solution
{
public:
    // Time: O(V+E), Space: O(V+E)
    bool canVisitAllRooms(vector<vector<int> > &rooms)
    {
        int n = rooms.size();
        vector<bool> visited(n, false);
        int source = 0;
        dfs(source, rooms, visited);

        for (int i = 0; i < visited.size(); i++)
        {
            if (!visited[i])
                return false;
        }
        return true;
    }

    void dfs(int v, vector<vector<int> > &rooms, vector<bool> &visited)
    {
        visited[v] = true;

        for (auto itr : rooms[v])
        {
            if (!visited[itr])
            {
                dfs(itr, rooms, visited);
            }
        }
    }
};
