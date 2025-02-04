// Imporiting ArrayList class
import java.util.ArrayList;
import java.util.Comparator;
import java.awt.Point;

// MapItem class used for MapItemTypes list of strings in main.java
class MapItem
{
	// create variables for x and y.  Type variable for index of MapItemTypes list
	private int x;
	private int y;
	public int type;
	public int scale;

	// Constructor function
	protected MapItem(int x, int y, int type, int scale)
	{
		this.x = x;
		this.y = y;
		this.type = type;
		this.scale = scale;
	}

	// Position getter
	Point pos(int time)
	{
		return new Point(this.x, this.y);
	}

	// Getters for x
	int getX()
	{
		return this.x;
	}

	// Getters for y
	int getY()
	{
		return this.y;
	}

	// Marshal function to create a json object
	public Json marshal()
	{
		// Create a json object
		Json ob = Json.newObject();
		// Add x, y, and type to the json object
		ob.add("x", this.x);
		ob.add("y", this.y);
		ob.add("type", this.type);
		return ob;
	}

	// Unmarshal constructor to create a MapItem object from a json object
	public static MapItem unmarshal(Json list_of_map_items)
	{
		return newItem(list_of_map_items.getInt("x"), list_of_map_items.getInt("y"), list_of_map_items.getInt("type"));
	}

	// Static function to create a new MapItem object
	public static MapItem newItem(int x, int y, int type) {
		if (type == 3 || type == 9)
			return new Jumper(x, y, type);
		else if (type == 4 || type == 7)
			return new Strafe(x, y, type);
		else if (type == 2)
			return new Scale(x, y, type);
		else
			return new MapItem(x, y, type, 0);
	}
}

class Jumper extends MapItem
{
	// Constructor using super
	Jumper(int x, int y, int type)
	{
		super(x, y, type, 0);
	}

	Point pos(int time)
	{
		return new Point(this.getX(), this.getY() - (int)Math.max(0., 50 * Math.sin(((double)time) * 2 * Math.PI / 30)));
	}
}

class Strafe extends MapItem
{
	// Constructor using super
	Strafe(int x, int y, int type)
	{
		super(x, y, type, 0);
	}

	Point pos(int time)
	{
		return new Point(this.getX() + (int)(50 * Math.sin(((double)time) * 2 * Math.PI / 30)), this.getY());
	}
}

class Scale extends MapItem
{
	// Constructor using super
	Scale(int x, int y, int type)
	{
		super(x, y, type, 0);
	}

	Point pos(int time)
	{
		this.scale = (int)(50*(Math.sin(((double)time) * 2 * Math.PI / 30)+.5));
		return new Point(this.getX(), this.getY());
	}
}

// Sorts map items by their y-values
class ItemYComparator implements Comparator<MapItem>
{
	// Returns a negative value if a.y > b.y
	// Returns zero if a.y == b.y
	// Returns a positive value if a.y < b.y
	public int compare(MapItem a, MapItem b) {
		int a_y = a.getY();
		int b_y = b.getY();
		return a_y - b_y;
    }
}

// Model class
class Model
{
	// Dynamic array (similar to vector in C++)
	ArrayList<MapItem> items;
	// x and y used as variables for mapItems spawn point.  Current item is index for MapItemTypes
	int x;
	int y;
	// public variables used by other classes
	public int current_item;
	public int scroll_x;
	public int scroll_y;
	public int scale;
	// Comparator for sorting items by y-value
	ItemYComparator c;

	// Model constructor
	Model()
	{
		// Create an array list for the items
		this.items = new ArrayList();
		this.x = 100;
		this.y = 100;
		this.c = new ItemYComparator();
		this.scroll_x = 0;
		this.scroll_y = 0;
		this.scale = 1;
	}

	// JSON marshal method
	public Json marshal()
	{
		// Create a json object
		Json map = Json.newObject();
		// Create a json list object
		Json list_of_map_items = Json.newList();
		Json coordinates = Json.newList();
		// Add the list json object, to the map json object(in a dict style)
		map.add("items", list_of_map_items);
		map.add("coordinates", coordinates);
		// Loop through the items array and add them to the list of map items
		for (MapItem item : this.items)
		{
			list_of_map_items.add(item.marshal());
		}
		coordinates.add(this.scroll_x);
		coordinates.add(this.scroll_y);
		this.items.clear();
		return map;
	}

	// JSON unmarshal method
	public Model unmarshal(Json ob)
	{
		// Get the list of map items from the json object
		Json list_of_map_items = ob.get("items");
		//Get previous scroll coordinates
		Json coordinates = ob.get("coordinates");
		this.scroll_x = coordinates.getInt(0);
		this.scroll_y = coordinates.getInt(1);
		// Loop through the list of map items
		for (int i = 0; i < list_of_map_items.size(); i++)
		{
			// Add the map item to the items array
			this.items.add(MapItem.unmarshal(list_of_map_items.get(i)));
		}
		return this;
	}

	// Function to addMapItems into items (the dynamic array list)
	public void addMapItem(int x, int y, int current_item)
	{
		MapItem i = MapItem.newItem(x, y, this.current_item);
		this.items.add(i);
	}

	// Increments current_item to loop through the list
	public void change_item()
	{
		this.current_item += 1;
		// If all items have been looped through, reset index to 0 to restart list
		if(this.current_item > (Main.MapItemTypes.length-1))
		{
			this.current_item = 0;
		}
	}

	public void update()
	{   
		this.items.sort(c);
	}

    public void reset()
    {
        this.x = 200;
        this.y = 200;
    }
	
}

