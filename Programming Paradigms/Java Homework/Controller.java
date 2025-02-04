// Imports
import java.awt.event.MouseListener;
import java.awt.event.MouseEvent;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.KeyListener;
import java.awt.event.KeyEvent;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;

class Controller implements ActionListener, MouseListener, KeyListener
{
	View view;
	Model model;
	boolean keyLeft;
	boolean keyRight;
	boolean keyUp;
	boolean keyDown;

	// Constructor for controller
	// Controller needs a reference to a model 
	Controller(Model m, View v)
	{
		this.model = m;
		this.view = v;
		this.view.addMouseListener(this);
		this.view.save_button.addActionListener(this);
		this.view.load_button.addActionListener(this);
		
	}

	public void actionPerformed(ActionEvent e)
	{
		// If save button is pressed
		if(e.getSource() == this.view.save_button)
		{
			try {
				FileWriter writer = new FileWriter("map.json");
				writer.write(this.model.marshal().toString());
				writer.close();
			} catch (IOException exception) {
				exception.printStackTrace();
				System.exit(1);
			}
		}
		// If load button is pressed
		else if (e.getSource() == this.view.load_button)
		{
			try {
				String content = new String(Files.readAllBytes(Paths.get("map.json")));
				Json map = Json.parse(content);
				this.model.unmarshal(map);
			} catch (IOException exception) {
				exception.printStackTrace();
				System.exit(1);
			}
		} 
	}
	
	// Function to add images when a mouse is pressed
	public void mousePressed(MouseEvent e)
	{
		// If left mouse button is pressed
		if (e.getButton() == 1)
		{
			// If mouse was pressed in purple box change the image
			if (e.getX() < 200 && e.getY() < 200) {
				
				this.model.change_item();
				return;
			}
			// Else add map item where user clicked the mouse
			else
			{
				//Add scroll_x and scroll_y to converte view coordinates into model coordinates
				this.model.addMapItem(e.getX()+this.model.scroll_x, e.getY()+this.model.scroll_y, this.model.current_item);
			}
			
		}
		// If right mouse button is pressed
		else if (e.getButton() == 3)
		{
			//if at least one element exists, find element to remove by using euclidean distance
			if(this.model.items.size() > 0)
			{
				// get x and y of mouse click
				int mouse_x = e.getX();
				int mouse_y = e.getY();
				double shortest_distance = 0;
				int item_x = 0;
				int item_y = 0;
				int closest_element = 0;

				// loop through array list to find closest element
				for(int i = 0; i < model.items.size(); i++)
				{
					// get current element
					MapItem item = model.items.get(i);

					// get x and y of current element
					// subtract scoll_x and scroll_y to convert model coordinates to view coordinates
					item_x = item.getX() - model.scroll_x;
					item_y = item.getY() - model.scroll_y;
					

					// calculate distance between mouse click and current element
					double distance = Math.sqrt((mouse_x - item_x) * (mouse_x - item_x) + (mouse_y - item_y) * (mouse_y - item_y));
					
					// if this distance is the shortest so far, save it
					if(i == 0 || distance < shortest_distance)
					{
						shortest_distance = distance;
						closest_element = i;
					}
				}
				// remove the closest element
				model.items.remove(closest_element);
			}
		}
	}

	public void mouseReleased(MouseEvent e) 
	{	}
	
	public void mouseEntered(MouseEvent e) 
	{	}
	
	public void mouseExited(MouseEvent e) 
	{	}
	
	public void mouseClicked(MouseEvent e) 
	{	}
	
	public void keyPressed(KeyEvent e)
	{
		switch(e.getKeyCode())
		{
			case KeyEvent.VK_RIGHT: 
				this.keyRight = true; 
				break;
			case KeyEvent.VK_LEFT: 
				this.keyLeft = true; 
				break;
			case KeyEvent.VK_UP: 
				this.keyUp = true; 
				break;
			case KeyEvent.VK_DOWN: 
				this.keyDown = true; 
				break;
		}
	}

	public void keyReleased(KeyEvent e)
	{
		switch(e.getKeyCode())
		{
			case KeyEvent.VK_RIGHT: 
				this.keyRight = false; 
				break;
			case KeyEvent.VK_LEFT: 
				this.keyLeft = false; 
				break;
			case KeyEvent.VK_UP: 
				this.keyUp = false; 
				break;
			case KeyEvent.VK_DOWN: 
				this.keyDown = false; 
				break;
			case KeyEvent.VK_ESCAPE:
				System.exit(0);
		}
		char c = Character.toLowerCase(e.getKeyChar());
		if(c == 'q')
			System.exit(0);
        if(c == 'r')
            this.model.reset();
	}

	public void keyTyped(KeyEvent e)
	{	}
	
	void update()
	{
		if(this.keyRight)
		{
			this.model.scroll_x -= 20;
		}
		if(this.keyLeft)
		{
			this.model.scroll_x += 20;
		}
		if(this.keyUp)
		{
			this.model.scroll_y += 20;
		}
		if(this.keyDown)
		{
			this.model.scroll_y -= 20;
		}
	}
}
