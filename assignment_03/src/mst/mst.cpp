#include "mst.h"

void outputMST(const string & file, KruskalResult & k_result, PrimsResult & p_result, double duration1, double duration2){
    fs::create_directories("assignment_03/outputs");
    string outFile = "assignment_03/outputs/" + fs::path(file).stem().string()+ "_" + "out.txt";
    ofstream out(outFile);

    out<<"Algorithm: Kruskal's MST"<<endl;
    out<<"MST edges: "<<endl;
    for(auto edge:k_result.mst){
        out<<edge.u<<" "<<edge.v<<" "<<edge.w<<endl;
    }
    out<<"Total MST weight: "<<k_result.mst_weight<<endl;
    out<<"Execution time: "<<duration1<<endl<<endl<<endl;

    out<<"Algorithm: Prim's MST "<<endl;
    out<<"MST edges: "<<endl;
    for(auto edge:p_result.mst){
        out<<edge.u<<" "<<edge.v<<" "<<edge.w<<endl;
    }
    out<<"Total MST weight: "<<p_result.mst_weight<<endl;
    out<<"Execution time: "<<duration2<<endl;
    cout<<"Total MST weight of kruskal: "<<k_result.mst_weight<<endl;
    cout<<"Total MST weight of prims: "<<p_result.mst_weight<<endl;
    cout << "Time taken by kruskal: " << duration1 << " ms" << endl;
    cout <<"Time taken by prims: " << duration2 <<" ms"<<endl;
}

void driverMST(){
    int choice = Menu::chooseInputMenu();

    switch(choice){
        case 1:{
                string file = chooseTestFile("./assignment_03/tests");
                AdjListWeighted g = readWeightedGraph(file);

                CSR csr = buildCSR(g);
                auto start = chrono::high_resolution_clock::now();
                KruskalResult k_result = kruskal(csr);
                auto end = chrono::high_resolution_clock::now();
                auto duration1 = chrono::duration<double, milli>(end-start).count();

                start = chrono::high_resolution_clock::now();
                PrimsResult p_result = prims(csr);
                end = chrono::high_resolution_clock::now();
                auto duration2 = chrono::duration<double,milli>(end-start).count();
                outputMST(file, k_result, p_result, duration1, duration2);

            break;
        }
        case 2:{
            vector<string> files = getTestFiles("./assignment_03/tests");

            for(string file : files){
                cout << "\nRunning "<< fs::path(file).filename().string()<< endl;

                AdjListWeighted g = readWeightedGraph(file);
                CSR csr = buildCSR(g);
                auto start = chrono::high_resolution_clock::now();
                KruskalResult k_result = kruskal(csr);
                auto end = chrono::high_resolution_clock::now();
                auto duration1 = chrono::duration<double, milli>(end-start).count();

                start = chrono::high_resolution_clock::now();
                PrimsResult p_result = prims(csr);
                end = chrono::high_resolution_clock::now();
                auto duration2 = chrono::duration<double,milli>(end-start).count();
                outputMST(file, k_result, p_result, duration1, duration2);
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
                auto start = chrono::high_resolution_clock::now();
                KruskalResult k_result = kruskal(csr);
                auto end = chrono::high_resolution_clock::now();
                auto duration1 = chrono::duration<double, milli>(end-start).count();

                start = chrono::high_resolution_clock::now();
                PrimsResult p_result = prims(csr);
                end = chrono::high_resolution_clock::now();
                auto duration2 = chrono::duration<double,milli>(end-start).count();
                outputMST(path, k_result, p_result, duration1, duration2);
            break;
        }
        default:
            cout<<"wrong"<<endl;
            return;
    }
}