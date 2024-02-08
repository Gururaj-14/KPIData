
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
