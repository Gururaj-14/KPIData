pipeline {
    agent any
    
    environment {
        QT_INSTALL_DIR = "C:\\Qt\\5.14.2\\mingw73_64\\bin" // Update with your Qt installation directory
        PROJECT_DIR = 'plcsimulator' // Update with your project directory
        EXAMPLE_BRANCH = 'example' // Branch containing the Qt code
        DEV_BRANCH = 'Dev' // Branch where the executable will be pushed
    }

    stages {
        stage('Checkout') {
            steps {
                // Checkout the example branch
		//git clone "https://github.com/Gururaj-14/KPIData.git"
		//git checkout "example"
        git branch: "example", url: 'https://github.com/Gururaj-14/KPIData.git'
            }
        }
        stage('Build') {
            steps {
                // Navigate to the project directory
                bat "cd ${PROJECT_DIR}"
                
                bat "g++ --version"
                // Run qmake to generate the Makefile
                bat "cd ${PROJECT_DIR} &&  ${QT_INSTALL_DIR}\\qmake.exe plcsimulator.pro -spec win32-g++ && C:\\Qt\\Tools\\mingw730_64\\bin\\mingw32-make.exe"
                
                // Build the project
                //bat "mingw32-make.exe"
            }
        }
        stage('Release') {
            steps {
                // Copy the executable to a known location
                bat "copy ${PROJECT_DIR}\\release\\plcsimulator.exe ."
                bat "C:\\Qt\\5.14.2\\mingw73_64\\bin\\windeployqt.exe --release --no-compiler-runtime plcsimulator.exe"
            }
        }
        stage('Deploy') {
            steps {
                // Checkout the dev branch
                git branch: "${DEV_BRANCH}", url: 'https://github.com/Gururaj-14/KPIData.git'
                
                // Copy the executable to the repository

                //bat "copy plcsimulator.exe ${PROJECT_DIR}\\example_plc.exe"
                
                // Add, commit, and push the executable to the dev branch
                bat "git add ${PROJECT_DIR}\\example_plc.exe"
                bat "git commit -m 'Add executable'"
                bat "git push origin ${DEV_BRANCH}"
            }
        }
    }
}

