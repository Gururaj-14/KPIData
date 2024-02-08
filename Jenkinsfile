
pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                script {
                    // Check if the directory exists
                    if (!fileExists('KPIData'){
                        git clone "https://github.com/Gururaj-14/KPIData.git/";
                    } else {
                        echo 'Directory "KPIData" already exists, skipping cloning.';
                    }
                }
            }
        }
        stage('Run') {
            steps {
                // Navigate to the directory where the code is cloned
                //dir('KPIData') {
                    // Compile the C++ program
                script{
                "C:\\msys64\\ucrt64\\bin\\g++.exe" hello_world.cpp
                }
                    //bat '"C:\\msys64\\ucrt64\\bin\\g++.exe" hello_world.cpp';
                    //echo 'finished';
                //}
            }
        }
    }
}
