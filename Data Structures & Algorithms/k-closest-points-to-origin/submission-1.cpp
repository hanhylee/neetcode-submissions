class Solution {
public:
    double distFromOrigin(int x, int y) {
        return (double) sqrt(x*x + y*y);
    }

    struct Point {
        double dist;
        int x;
        int y;

        Point(double dist, int x, int y) : dist(dist), x(x), y(y) {};

        bool operator>(const Point& other) const {
            return dist > other.dist;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        /*INPUT
        given vector<vector<int>> points 
        each point represents the coordinates of a point on an X-Y plane
        given int k
        */
        
        /*APPROACH
        int dist(p1,p2) {
            return sqrt((x1 - x2)^2 + (y1 - y2)^2));
        }

        for each point, calculate euclidean distance to origin and insert into a min heap
        pop k points and return their coordinates
        */
        priority_queue<Point, vector<Point>, greater<Point>> min_heap;

        for (const auto& coord: points) {
            int x = coord[0];
            int y = coord[1];
            double dist = distFromOrigin(x, y);
            cout << "x: " << x << ", y: " << y << ", dist: " << dist << "\n";
            min_heap.push(Point(dist, x, y));
        }

        /*OUTPUT
        return k closest points to the origin
        */
        vector<vector<int>> res;

        for (int i=0; i<k; i++) {
            Point point = min_heap.top();
            min_heap.pop();
            vector<int> coords = {point.x, point.y};
            res.push_back(coords);
        }

        return res;
    }
};
