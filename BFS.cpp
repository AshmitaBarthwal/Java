import java.util.*;

public class BFS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take input for number of vertices and edges
        System.out.println("Enter the number of vertices: ");
        int vertices = sc.nextInt();

        System.out.println("Enter the number of edges: ");
        int edges = sc.nextInt();

        // Initialize adjacency list
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            adj.add(new ArrayList<>());
        }

        // Take input for edges
        System.out.println("Enter the edges (format: u v for edge u -> v): ");
        for (int i = 0; i < edges; i++) {
            int u = sc.nextInt(); // Start vertex
            int v = sc.nextInt(); // End vertex
            adj.get(u).add(v); // Add directed edge u -> v
            adj.get(v).add(u); // For undirected graph, also add v -> u
        }

        // BFS variables
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[vertices];

        // Input for starting BFS vertex
        System.out.println("Enter the starting vertex: ");
        int start = sc.nextInt();

        // Start BFS
        visited[start] = true;
        queue.add(start);

        System.out.println("Breadth First Search starting from vertex " + start + ":");

        while (!queue.isEmpty()) {
            int node = queue.poll(); // Dequeue a vertex
            System.out.print(node + " ");

            // Visit all unvisited neighbors
            for (int neighbor : adj.get(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }

        sc.close();
    }
}
