pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                git 'https://github.com/Gururaj-14/KPIData.git'
            }
        }
        stage('Build') {
            steps {
                sh 'make'
                // Or use cmake, g++, etc. depending on your build process
            }
        }
        // Add more stages for testing, packaging, etc. as needed
    }
}
