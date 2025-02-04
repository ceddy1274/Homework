// Imports
import javax.swing.JPanel;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import java.io.File;
import javax.swing.JButton;
import java.awt.Color;
import java.awt.Point;


// Extends JPanel is used to draw stuff
class View extends JPanel
{
	// Array of buffered images
	static BufferedImage[] item_images;
	Model model;
	// Load and save buttons
	JButton save_button;
	JButton load_button;
	// Time
	int time;

	// Constructor for the model
	View(Model m)
	{
		this.model = m;

		// Make the save button
		this.save_button = new JButton("Save");
		this.add(save_button);
		save_button.setFocusable(false);

		// Make the load button
		this.load_button = new JButton("Load");
		this.add(load_button);
		load_button.setFocusable(false);

		// Load the images
		this.item_images = new BufferedImage[Main.MapItemTypes.length];
		for (int i = 0; i < Main.MapItemTypes.length; i++) {
			BufferedImage image = null;
			try
			{
				image = ImageIO.read(new File("images/" + Main.MapItemTypes[i] + ".png"));
			} catch(Exception e) {
				e.printStackTrace(System.err);
				System.exit(1);
			}
			this.item_images[i] = image;
		}

	}

	// Always clear the screen in paint compenent method
	public void paintComponent(Graphics g)
	{
		// Increase time
		this.time++;

		// Clear the background
		g.setColor(new Color(64, 255, 128));
		g.fillRect(0, 0, this.getWidth(), this.getHeight());

		// Draw all the item images
		for (int i = 0; i < model.items.size(); i++) {
			MapItem item = model.items.get(i);
			BufferedImage image = this.item_images[item.type];
			int w = image.getWidth();
			int h = image.getHeight();
			Point p = item.pos(this.time);
			
			int dx1 = p.x - w / 2 - this.model.scroll_x - item.scale;
			int dy1 = p.y - h - this.model.scroll_y - 2*item.scale;
			int dx2 = p.x + w / 2 - this.model.scroll_x + item.scale;
			int dy2 = p.y - this.model.scroll_y;
			
			// Draw the image with the bottom center at (x, y)
			// Subtract scroll_x and scroll_y to converte model coordinates to view coordinates
			
			g.drawImage(image, dx1, dy1, dx2, dy2, 0, 0, w, h, null);
		}

		// Purple box
		g.setColor(new Color(100,0,100));
		g.fillRect(0,0,200,200);
		// Draw current image in top left box
		BufferedImage image = this.item_images[model.current_item];
		int w = image.getWidth();
		int h = image.getHeight();
		g.drawImage(image, 100 - w/2 , 200 - h, null);
	}
}
