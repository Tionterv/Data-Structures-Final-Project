# Data-Structures-Final-Project


# Summary
One of the main reasons to use Dijkstra’s algorithm is the number of important and
useful applications available for generating (exact) optimal solutions to a large class of
shortest path problems. For example, Digital Mapping Services in Google Maps, Social
Networking Applications, Telephone Network, IP routing to find Open shortest Path
First, and Flighting Agenda.


Let’s say that the distance from a non-negative vertex a to b in a plane P is represented
by d(a,b) and this is the shortest length path (also called shortest path) from a to b if
there is a path that connects a to b. To find this shortest path we take a greedy
approach to this problem which means that at every step we select the best choice
available at that step without regard to future consequences to find the optimal choice at
the end.

Here is how it works in theory:


1. We will pick the vertex with the smallest known weight to visit first.
2. Once we’ve moved to the vertex we’re going to visit, we will check each of its
neighboring vertex.
3. For each neighboring vertices , we’ll calculate the weight by summing the weight
of the edges that lead to the vertex we’re checking.
4. Finally, if the weight is less than a known distance, we’ll update the shortest
distance that we have on file for that vertex.


When the algorithm terminates (when no more vertices are left to visit), at which point
we have a shortest path from a to every other vertex of the plane of P.


# Implementation
The following was done using a priority queue, using weight and label as the key and
value.


Starting the values were initialized to empty strings and infinity for the weight. The next
implementation was to add a starting point to the priority queue and check if the priority
queue was not empty. If it was not empty, then we would check for all adjacent
neighbors and their weights to compare then and select the smallest one. We’ll continue
doing the same steps for each vertex that remains unvisited until we visit each vertex
and find our destination vertex.


To create a weighted graph we had the functions addVertex, removeVertex, addEdge,
removeEdge. The addVertex function uses a for-loop to go through each vertex in a
vector. It compares each vertex’s label with the one passed from the function call. The
label is pushed into the vector if it doesn’t exist in there. For the removeVertex function
when we want to delete a vertex, we use a for-loop to find the matching labels and
delete the vertex along with its associated edges. On the addEdge function we are
provided with two labels that are used in a for-loop to go through each vertex and if they
are matched then the edge would be added into
