# Map Editor in Java

## 📌 Overview
This project was the made up of the first three homework assignments for the Programming Paradigms class. The first assignment was an introduction to Java. The second was to use JSON to create a map editor that could save and load data. The third assignment was to use polymorphism to make a statue strafe, a mushroom grow, and a turtle jump.

## 📥 How to Download This Folder

### Option 1: Download the Entire Repository
1. Clone the entire repository:
   ```bash
   git clone https://github.com/ceddy1274/Homework.git
   ```
2. Navigate to the Java Homework folder:
   ```bash
   cd "Homework/Programming Paradigms/Java Homework"
   ```

### Option 2: Download Just This Folder (using GitHub CLI)
If you have GitHub CLI installed:
```bash
gh repo clone ceddy1274/Homework
cd "Homework/Programming Paradigms/Java Homework"
```

### Option 3: Download as ZIP
1. Go to the [main repository page](https://github.com/ceddy1274/Homework)
2. Click the green "Code" button
3. Select "Download ZIP"
4. Extract the ZIP file and navigate to `Programming Paradigms/Java Homework/`

### Option 4: Download Individual Files
You can download individual files directly from GitHub by:
1. Navigate to the [Java Homework folder](https://github.com/ceddy1274/Homework/tree/main/Programming%20Paradigms/Java%20Homework)
2. Click on each file and then click "Raw" button
3. Right-click and "Save as..." to download each file

## 🛠️ Prerequisites
- Java Development Kit (JDK) 8 or higher
- A terminal/command prompt to run the bash/batch scripts

## 🚀 How to Run After Downloading

### Quick Start
Once you have downloaded the folder:

**On Linux/Mac:**
```bash
chmod +x run.bash
./run.bash
```

**On Windows:**
```batch
run.bat
```

### Manual Compilation and Execution
If the scripts don't work, you can manually compile and run:
```bash
javac Main.java View.java Controller.java Model.java Json.java
java Main
```

## 📂 Folder Structure
The Java files are all different files needed for the common Model, View, Controller architecture seen in programming. The view is what a user can currently see, the model is what is happening in the entire world of thr program, and the controller is how the program handles inputs from the user. Main.java is what interconnects the model, view, and controller to make the game work. There is also a map.json and folder for images which allows the user to put images onto the screen, save the image positions, and then reload the images which is a common technique used to save the current state of programs. Finally, the run.bash file is a bash script used to make running the program quicker and increase productivity. If on a windows machine (which is what I used), use the run.bat file.

### File Descriptions
- **Main.java** - Entry point that connects MVC components
- **Model.java** - Handles the game world and logic
- **View.java** - Manages the visual display
- **Controller.java** - Handles user input and interactions
- **Json.java** - Manages saving/loading map data from JSON
- **map.json** - Stores map state data
- **images/** - Contains PNG files for game objects
- **run.bash** - Linux/Mac run script
- **run.bat** - Windows run script


