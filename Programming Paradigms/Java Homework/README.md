# Map Editor in Java

## 📌 Overview
This project was the made up of the first three homework assignments for the Programming Paradigms class. The first assignment was an introduction to Java. The second was to use JSON to create a map editor that could save and load data. The third assignment was to use polymorphism to make a statue strafe, a mushroom grow, and a turtle jump.

## 💾 How to Download and Run

### Prerequisites
- **Java Development Kit (JDK) 8 or higher** - Download from [Oracle](https://www.oracle.com/java/technologies/downloads/) or [OpenJDK](https://openjdk.org/)
- **Git** (optional, for cloning) - Download from [git-scm.com](https://git-scm.com/)
- A system with **GUI support** (the application uses Java Swing)

### Download Options

#### Option 1: Clone the Repository (Recommended)
```bash
git clone https://github.com/ceddy1274/Homework.git
cd "Homework/Programming Paradigms/Java Homework"
```

#### Option 2: Download ZIP
1. Go to [https://github.com/ceddy1274/Homework](https://github.com/ceddy1274/Homework)
2. Click the green "Code" button
3. Select "Download ZIP"
4. Extract the ZIP file
5. Navigate to `Homework/Programming Paradigms/Java Homework/`

### Running the Application

#### On Linux/macOS:
```bash
# Make the script executable (first time only)
chmod +x run.bash

# Run the application
./run.bash
```

#### On Windows:
```cmd
# Double-click run.bat in File Explorer, or run from Command Prompt:
run.bat
```

#### Manual compilation (any platform):
```bash
# Compile the Java files
javac Main.java View.java Controller.java Model.java Json.java

# Run the application
java Main
```

### 🎮 How to Use
- The application will open a graphical map editor window
- You can place various items on the map (chairs, lamps, mushrooms, etc.)
- Items can be saved to and loaded from `map.json`
- Some items have special animations:
  - **Statue**: Strafes (moves side to side)
  - **Mushroom**: Grows in size
  - **Turtle**: Jumps

### 🛠️ Troubleshooting

#### "java: command not found"
- Install Java JDK and ensure it's in your system PATH
- Test with: `java -version` and `javac -version`

#### "HeadlessException" or GUI doesn't appear
- Ensure you're running on a system with GUI support
- On Linux servers, you may need X11 forwarding: `ssh -X username@server`

#### Compilation warnings about "unchecked operations"
- These are safe to ignore - the program will still run correctly
- To see details: `javac -Xlint:unchecked *.java`

## 📂 Folder Structure
The Java files are all different files needed for the common Model, View, Controller architecture seen in programming. The view is what a user can currently see, the model is what is happening in the entire world of the program, and the controller is how the program handles inputs from the user. Main.java is what interconnects the model, view, and controller to make the game work. There is also a map.json and folder for images which allows the user to put images onto the screen, save the image positions, and then reload the images which is a common technique used to save the current state of programs. Finally, the run.bash file is a bash script used to make running the program quicker and increase productivity. If on a windows machine (which is what I used), use the run.bat file.

### File Descriptions
- `Main.java` - Entry point and main application class
- `View.java` - GUI components and rendering
- `Controller.java` - Input handling and user interactions
- `Model.java` - Game logic and data management
- `Json.java` - JSON parsing for save/load functionality
- `map.json` - Saved map data
- `images/` - Folder containing item images
- `run.bash` - Linux/macOS run script
- `run.bat` - Windows run script


