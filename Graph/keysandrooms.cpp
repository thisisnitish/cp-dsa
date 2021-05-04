/*
Leetcode Question 841. Keys and Rooms
https://leetcode.com/problems/keys-and-rooms/
*/

class Solution
{
public:
    /*the basic idea is, since the question is asking visit the every room,
    so definately we have to use traversal, so, we are using dfs.
    Time: O(N+E), Space: O(N)*/
    bool canVisitAllRooms(vector<vector<int> > &rooms)
    {
        int n = rooms.size();
        vector<bool> visited(n, false);
        int source = 0;
        //since we have to start dfs from the source node only
        dfs(source, rooms, visited);

        //checking that every node is visited or not
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