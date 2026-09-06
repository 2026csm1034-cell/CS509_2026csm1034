#include "driver.h"

void outputPageRank(const string &file, const PageRankResult &result, double duration) {
    string fileName = createOutputFiles4(file, "pageRank");
    ofstream outputFile(fileName);
 
    outputFile << "Algorithm: PageRank" << "\n";
    outputFile << "Damping: " << result.d << "\n";
 
    outputFile << "Vertex ranks:" << "\n";
    outputFile << fixed << setprecision(6);
    for (const auto &p : result.rank) {
        outputFile << p.first << " " << p.second << "\n";
    }
 
    outputFile << "Sum of ranks: " << result.totalRank << "\n";
    outputFile << defaultfloat;
    outputFile << "Iterations: " << result.itration << "\n";
    outputFile << "Converged: " << (result.isConverged ? "true" : "false") << "\n";
    outputFile << "Execution time: " << duration << " ms" << "\n";
 
    cout << "Output File Generated : " << fileName << endl;
    cout << "V=" << result.rank.size() << "  Sum of ranks: "
         << fixed << setprecision(6) << result.totalRank << endl;
    cout << defaultfloat << "Iterations: " << result.itration
         << "  Converged: " << (result.isConverged ? "true" : "false") << endl;
    cout << "Execution Time: " << duration << " ms" << endl;
}

void driverPageRank(){
    int choice = Menu::chooseInputMenu();

    switch(choice){
        case 1:{
                string file = chooseTestFile("./assignment_04/tests/pageRank");
                PageRankGraph g = readPageRankGraph(file);

                CSR csr = build1CSR(g);
                auto start = chrono::high_resolution_clock::now();
                PageRankResult result = pageRank(csr, g.d, g.n, g.epsilon);
                auto end = chrono::high_resolution_clock::now();
                auto duration1 = chrono::duration<double, milli>(end-start).count();

                outputPageRank(file, result, duration1);

            break;
        }
        case 2:{
            vector<string> files = getTestFiles("./assignment_04/tests/pageRank");

            for(string file : files){
                cout << "\nRunning "<< fs::path(file).filename().string()<< endl;

                PageRankGraph g = readPageRankGraph(file);

                CSR csr = build1CSR(g);
                auto start = chrono::high_resolution_clock::now();
                PageRankResult result = pageRank(csr, g.d, g.n, g.epsilon);
                auto end = chrono::high_resolution_clock::now();
                auto duration1 = chrono::duration<double, milli>(end-start).count();
                
                outputPageRank(file, result, duration1);
            }
            break;
        }
        case 3:{
                string path;
                cout << "\nEnter file path : ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, path); 
                PageRankGraph g = readPageRankGraph(path);

                CSR csr = build1CSR(g);
                auto start = chrono::high_resolution_clock::now();
                PageRankResult result = pageRank(csr, g.d, g.n, g.epsilon);
                auto end = chrono::high_resolution_clock::now();
                auto duration1 = chrono::duration<double, milli>(end-start).count();
                
                outputPageRank(path, result, duration1);
            break;
        }
        default:
            cout<<"wrong"<<endl;
            return;
    }
}


void outputColor(const string &file, const VertexColorResult &result, double duration) {
   string fileName = createOutputFiles4(file, "color");
    ofstream outputFile(fileName);
 
    outputFile << "Algorithm: Greedy Vertex Coloring" << "\n";
 
    outputFile << "Vertex colors:" << "\n";
    for (size_t i = 0; i < result.colors.size(); ++i) {
        outputFile << i << " " << result.colors[i] << "\n";
    }
 
    outputFile << "Colors used: " << result.numColors << "\n";
    outputFile << "Execution time: " << duration << " ms" << "\n";
 
    cout << "Output File Generated : " << fileName << endl;
    cout << "V=" << result.colors.size() << "  Colors used: " << result.numColors << endl;
    cout << "Execution Time: " << duration << " ms" << endl;
}
void driverColor(){
    int choice = Menu::chooseInputMenu();

    switch(choice){
        case 1:{
                string file = chooseTestFile("./assignment_04/tests/color");

                UndirectedGraph g = readUndirectedGraph(file);
                CSR csr = build1CSR(g);

                auto start = chrono::high_resolution_clock::now();
                VertexColorResult result = colorVertices(csr);
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration<double, milli>(end-start).count();

                outputColor(file, result, duration);

            break;
        }
        case 2:{
            vector<string> files = getTestFiles("./assignment_04/tests/color");

            for(string file : files){
                cout << "\nRunning "<< fs::path(file).filename().string()<< endl;

                UndirectedGraph g = readUndirectedGraph(file);
                CSR csr = build1CSR(g);

                auto start = chrono::high_resolution_clock::now();
                VertexColorResult result = colorVertices(csr);
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration<double, milli>(end-start).count();

                outputColor(file, result, duration);
            }
            break;
        }
        case 3:{
                string path;
                cout << "\nEnter file path : ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, path); 
                UndirectedGraph g = readUndirectedGraph(path);
                CSR csr = build1CSR(g);

                auto start = chrono::high_resolution_clock::now();
                VertexColorResult result = colorVertices(csr);
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration<double, milli>(end-start).count();

                outputColor(path, result, duration);
            break;
        }
        default:
            cout<<"wrong"<<endl;
            return;
    }
}

void driverAssignment04(){

    while(true){
        int choice = Menu::showAlgorithm4Menu();
        switch(choice){
            case 1:
                driverPageRank();
                break;
            case 2:
                driverColor();
                break;
            case 0:
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return;
}