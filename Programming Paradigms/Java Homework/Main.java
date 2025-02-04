// Imports
import javax.swing.JFrame;
import java.awt.Toolkit;

// Main class
// JFrame is used for wrapping your program in a frame
// Extension gets all the variables of JFrame class
public class Main extends JFrame
{
	// Intalizing other classes
	Model model;
	Controller controller;
	View view;

	// Main constructors
	public Main()
	{
		// Instantiate the three main objects
		this.model = new Model();
		this.view = new View(model);
		this.controller = new Controller(model, view);

		// Set some window properties
		this.setTitle("Turtle Attack!");
		this.setSize(1000, 1000);
		this.setFocusable(true);
		this.getContentPane().add(view);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setVisible(true);
		this.addKeyListener(controller);
	}

	public void run()
	{
		// Main loop
		while(true)
		{
			this.controller.update();
			this.model.update();
			this.view.repaint(); // Indirectly calls View.paintComponent
			Toolkit.getDefaultToolkit().sync(); // Updates screen

			// Go to sleep for a brief moment
			try
			{
				Thread.sleep(25);
			} catch(Exception i) {
				i.printStackTrace();
				System.exit(1);
			}
		}
	}

	// Anything on the stack in java is either a primative type or a reference
	// Methods in java without a this parameter are static methods
	// Static methods are essentially global variables in Java
	// RULES:
	// 1) When possible use local variables
	// 2) When it makes sense, use member variables
	// 3) When you have to, use static variables
	public static void main(String[] args)
	{
		Main m = new Main();
		// m is a parameter to run method
		m.run();
	}

	// Array for map items
	// Final is used for something that does not change
	public static final String[] MapItemTypes = {
		"chair",
		"lamp",
		"mushroom",
		"outhouse",
		"pillar",
		"pond",
		"rock",
		"statue",
		"tree",
		"turtle",
	};
}
