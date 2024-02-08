
pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                script {
                    // Check if the directory exists
                    if (!fileExists('KPIData')) {
                        // Clone the code from the Git repository
                                                echo 'Directory "KPIData" already not exists, skipping cloning.'
                        git branch: 'main', url: 'git clone https://github.com/Gururaj-14/KPIData.git/'
                    } else {
                        echo 'Directory "KPIData" already exists, skipping cloning.'
                    }
                }
            }
        }
        stage('Run') {
            steps {
                // Navigate to the directory where the code is cloned
                //dir('KPIData') {
                    // Compile the C++ program
                    bat 'g++ -o hello_world.exe hello_world.cpp';
                    echo 'finished';
                //}
            }
        }
    }
}
