#include <iostream>
#include "Graph.h"
#include "Unigram.h"
#include "Model.h"
#include <string>
#include <sstream>

using namespace std;




int main() {

    stringstream graph_path, embedding;
    string dataset = "citeseer_undirected";

    graph_path << "/home/abdulkadir/Desktop/datasets/" << dataset << ".edgelist";
    //graph_path << "./" << dataset << ".edgelist";

    Graph g;
    g.readGraph(graph_path.str(), "edgelist", false);

    cout << "Number of nodes: " << g.getNumOfNodes() << endl;
    cout << "Number of edges: " << g.getNumOfEdges() << endl;

    double starting_alpha=0.025;
    double min_alpha=0.0001;
    double decay_rate=0.001;
    int num_of_iters=1000;
    int negative=5;
    int save_step=10;
    string save_file="/home/abdulkadir/Desktop/ego2emb/embeddings/";

    Model model(g, 128);
    model.run(starting_alpha, min_alpha, decay_rate, num_of_iters, negative, save_step, save_file);
    embedding << save_file << "deneme" << "_last.embedding";
    //embedding << "./" << dataset << "_last.embedding";
    
    model.save_embeddings(embedding.str());


    return 0;
}

