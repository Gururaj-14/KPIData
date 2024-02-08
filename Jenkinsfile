
pipeline {
    agent any
    

    stages {
        stage('Build') {
            steps {
                // Checkout the code from the Git repository
                bat 'git clone https://github.com/Gururaj-14/KPIData.git'
                
                // Navigate to the directory where the code is cloned
                dir('KPIData') {
                    // Compile the C++ program
                    bat 'g++ -o hello_world.exe hello_world.cpp'
                }
            }
        }
        stage('Run') {
            steps {
                // Navigate to the directory where the executable is located
                dir('KPIData') {
                    // Run the compiled program
                    bat 'hello_world.exe'
                }
            }
        }
    }
}
pipeline {
    agent any
    
    stages {
        stage('Build') {
            steps {
                // Checkout the code from the Git repository
                git 'https://github.com/Gururaj-14/KPIData.git'
               
                // Compile the C++ program
                sh 'g++ -o hello_world hello_world.cpp'
            }
        }
        stage('Run') {
            steps {
                // Run the compiled program
                sh './hello_world'
            }
        }
    }
}
