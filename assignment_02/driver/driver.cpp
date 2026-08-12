#include "driver.h"
void outputBellmanFord(const string& file, const BellmanFordResult& result, int source, double duration) {
    fs::create_directories("assignment_02/outputs/bellman_ford");
    string outputFile = "assignment_02/outputs/bellman_ford/" + fs::path(file).stem().string() + "_" + "out"+ ".txt";
    ofstream out(outputFile);
    out <<"Algorithm: Bellman-Ford\n";
    out<<"Source: "<< source << endl;
    if(!result.isNegativeCycle){
        out<<"Vertices "<<"Distances\n";
        for(int i=0; i<result.distances.size(); i++){
            if(result.distances[i] != LLONG_MAX){
                out<<i<<" "<<result.distances[i]<<endl;
            }else{
                out<<i<<" "<<"INF"<<endl;
            }
        }
        out<<"Negative Cycle: None"<<endl;
    }else{
        out<<"Negative Cycle: True"<<endl;
    }
    out<<"Time taken: " << duration<< " ms" << endl;
}

void helperBellmanFord(){
    int choice = Menu::chooseInputMenu();

    switch(choice){
        case 1:{
            string file = chooseTestFile("./assignment_02/tests/bellman_ford");

            AdjListWeighted g = readWeightedGraph(file);
            CSR csr = buildCSR(g);
            auto start = chrono::high_resolution_clock::now();
            BellmanFordResult result = bellman_ford(csr, g.src);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration<double,milli>(end-start).count();
            outputBellmanFord(file, result,g.src, duration);
            cout << "Time taken: " << duration << " ms" << endl;

            break;
        }

        case 2:{
            vector<string> files = getTestFiles("./assignment_02/tests/bellman_ford");

            for(string file : files){
                cout << "\nRunning "<< fs::path(file).filename().string()<< endl;

                AdjListWeighted g = readWeightedGraph(file);
                CSR csr = buildCSR(g);
                auto start = chrono::high_resolution_clock::now();
                BellmanFordResult result = bellman_ford(csr, g.src);
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration<double, milli>(end-start).count();

                outputBellmanFord(file, result, g.src, duration);
                cout << "Time taken: " << duration << " ms" << endl;
            }

            break;
        }

        case 3:{
            string path;

            cout << "\nEnter file path : ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, path);
            AdjListWeighted g = readWeightedGraph(path);
            CSR csr = buildCSR(g);
            cout<<"Running  : "<<path<<endl;
            auto start = chrono::high_resolution_clock::now();
            BellmanFordResult result = bellman_ford(csr, g.src);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration<double, milli>(end-start).count();
            outputBellmanFord(path, result, g.src, duration);
            cout<<"Output written to outputs forlder"<<endl;
            cout << "Time taken: " << duration << " ms" << endl;
            break;
        }

        case 0:
            cout<<"Going back to main menu..."<<endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

vector<vector<long long>> convertMat(const string & file){
    int V;
    ifstream inputFile(file);
    inputFile >> V;
    vector<vector<long long>> adjMat(V, vector<long long>(V, INF));
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            string literal;
            inputFile >> literal;
            if(literal != "INF"){
                adjMat[i][j] = stoll(literal);
            } 
        }
    }
    return adjMat;
}

void outputFloydWarshall(const string & file, const FloydWarshallResult & result, double duration){
    fs::create_directories("assignment_02/outputs/floyd_warshall");
    string outputFile = "assignment_02/outputs/floyd_warshall/" + fs::path(file).stem().string() + "_out" + ".txt";
    ofstream out(outputFile);
    out<<"Algorithm: Floyd-Warshall"<<endl;
    if(!result.isNegativeCycle){
        for(int i=0; i<result.dist.size(); i++){
            for(int j=0; j<result.dist[i].size(); j++){
                if(result.dist[i][j] == INF){
                    out << "INF ";
                } else {
                    out << result.dist[i][j] << " ";
                }
            }
            out << endl;
        }
        out<<"Negative Cycle: None"<<endl;
    }else{
        out<<"Negative Cycle: True"<<endl;
    }
    out << "Time taken: " << duration << " ms" << endl;
}

void helperFloydWarshall(){
     int choice = Menu::chooseInputMenu();
    switch(choice){
        case 1:{
            string file = chooseTestFile("./assignment_02/tests/floyd_warshall");
            vector<vector<long long>> adjMat = convertMat(file);
            // cout<<"Running .."<<fs::path(file).stem().string()<<endl;
            auto start = chrono::high_resolution_clock::now();
            FloydWarshallResult result = floydWarshall(adjMat);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration<double,milli>(end-start).count();
            outputFloydWarshall(file, result, duration);
            cout << "Time taken: " << duration << " ms" << endl;

            break;
        }

        case 2:{
            vector<string> files = getTestFiles("./assignment_02/tests/floyd_warshall");

            for(string file : files){
                cout << "\nRunning "<< fs::path(file).filename().string()<< endl;
                vector<vector<long long>> adjMat = convertMat(file);
                auto start = chrono::high_resolution_clock::now();
                FloydWarshallResult result = floydWarshall(adjMat);
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration<double, milli>(end-start).count();

                outputFloydWarshall(file, result, duration);
                cout << "Time taken: " << duration << " ms" << endl;
            }

            break;
        }

        case 3:{
            string path;

            cout << "\nEnter file path : ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, path);
            vector<vector<long long>> adjMat = convertMat(path);
            auto start = chrono::high_resolution_clock::now();
            FloydWarshallResult result = floydWarshall(adjMat);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration<double, milli>(end-start).count();
            outputFloydWarshall(path, result, duration);
            cout << "Time taken: " << duration << " ms" << endl;
            break;
        }

        case 0:
            cout<<"Going back to main menu..."<<endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}


void driverAssignment02(){
    int choice = Menu::showAlgorithm2Menu();

    switch(choice){
        case 0:
            return;

        case 1:
            helperBellmanFord();
            break;
        case 2:
            helperFloydWarshall();
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
    return;
}