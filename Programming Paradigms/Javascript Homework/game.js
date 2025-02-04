let game = null;
const id = Math.floor(Math.random() * 10000000);
let last_update_time = new Date();
let score = 0;
// Represents a moving image
class Sprite {
	constructor(x, y, image_url, name) {
		this.name = name;
		this.score = 0;
		this.id = id;
		this.x = x;
		this.y = y;
		this.type = null;
        this.speed = 120; // pixels-per-second
		this.image = new Image();
		this.image.src = image_url;
		
        // Set some default event handlers
		this.update = Sprite.prototype.update_stop;
		this.onleftclick = Sprite.prototype.onclick_ignore;
        this.onrightclick = Sprite.prototype.onclick_ignore;
        this.arrive = Sprite.prototype.update_stop;
	}

    // The default update behavior
	update_stop(elapsed_time) {
        delete this.dist_remaining; // causes the object to stop having the property
	}

    // Move forward
	update_travel(elapsed_time) {
		if(this.dist_remaining === undefined)
			return; // No destination to travel toward
        let dist_step = Math.min(this.dist_remaining, elapsed_time * this.speed);
        this.x += dist_step * this.component_x;
        this.y += dist_step * this.component_y;
        this.dist_remaining = this.dist_remaining - dist_step;
        if (this.dist_remaining === 0)
		{
           this.arrive();
		}
	}

    // Remove "this" from the list of sprites
    update_disappear(elapsed_time) {
        for (let i = 0; i < game.model.sprites.length; i++) {
            if (game.model.sprites[i] === this) {
				if(game.model.sprites[i].type === "fireball");
				{
					//loop through objects in model.sprites
					for(let j = 0; j < game.model.sprites.length; j++)
					{
						let fireball = this;
						if(game.model.sprites[j].type != "fireball")
						{
							let current = game.model.sprites[j];
							if(this.does_collide(fireball, current))
							{
								if(current.type != "robot")
								{
									game.model.sprites.splice(j, 1);
									if(fireball.name === game.model.avatar.name)
										score = 0;
								}
								else
								{
									if(fireball.name === game.model.avatar.name)
										score++;
								}
							}
						}
					}
					if(game.model.sprites[i].type === "fireball")
						game.model.sprites.splice(i, 1); // remove this sprite from the list
				}
                return;
            }
        }
        console.log('uh oh, I could not find this sprite in model.sprites!');
    }

	compute_rect() {
		if (this.right > 0)
			return;
		this.top = Number(this.y);
		//console.log(this.top);
		this.bottom = Number(this.y) + Number(this.image.height);
		//console.log(this.bottom);
		this.left = Number(this.x);
		//console.log(this.left);
		this.right = Number(this.x) + Number(this.image.width);
		//console.log(this.right);

	}

	does_collide(a, b) {
		a.compute_rect();
		b.compute_rect();
		if (a.right <= b.left)
		  return false;
		if (a.left >= b.right)
		  return false;
		if (a.bottom <= b.top)
		  return false;
		if (a.top >= b.bottom)
		  return false;
		//console.log("A: ")
		//console.log(a)
		//console.log("B: ")
		//console.log(b)
		//console.log("Collision detected");
		return true;
	}

    // Do nothing
	onclick_ignore(x, y) {
	}

    // Start travelling to the spot clicked
	onclick_set_destination(x, y) {
        let delta_x = x - this.x;
        let delta_y = y - this.y;
        this.dist_remaining = Math.sqrt(delta_x * delta_x + delta_y * delta_y);
		this.component_x = delta_x / Math.max(1e-6, this.dist_remaining);
        this.component_y = delta_y / Math.max(1e-6, this.dist_remaining);
	}

    // Throw a fireball toward the spot clicked
    onclick_throw_fireball(x, y, name) {
		let fireball = new Sprite(this.x, this.y, "fireball.png", this.name);
        fireball.speed = 300; // pixels-per-second
		fireball.type = "fireball";
        fireball.update = Sprite.prototype.update_travel;
        fireball.arrive = Sprite.prototype.update_disappear;
        let delta_x = x - this.x;
        let delta_y = y - this.y;
        fireball.dist_remaining = Math.sqrt(delta_x * delta_x + delta_y * delta_y);
        fireball.component_x = delta_x / fireball.dist_remaining;
        fireball.component_y = delta_y / fireball.dist_remaining;
		game.model.sprites.push(fireball);
    }
}




class Model {
	constructor(name) {
		this.name = name;
		this.sprites = [];
		this.fireball_ids = [];
		this.map = undefined;
		this.imageIndex = 0;
        // Make the avatar
		this.avatar = new Sprite(500, 250, "robot.png", name);
		this.avatar.type = "robot";
        this.avatar.update = Sprite.prototype.update_travel;
        this.avatar.onleftclick = Sprite.prototype.onclick_set_destination;
        this.avatar.onrightclick = Sprite.prototype.onclick_throw_fireball;
		this.avatar.id = id;
		this.sprites.push(this.avatar);
		this.loadImages();
        this.last_update_time = new Date();
		this.scroll_x = 0;
		this.scroll_y = 0;
	}

	update() {
		//if not pushed yet, send to server
        let now = new Date();
        let elapsed_time = (now - this.last_update_time) / 1000; // seconds
        this.avatar.score = score;
		//let el = document.getElementById("score");
		//el.innerHTML = `${this.avatar.name}'s Score: ${this.avatar.score}`;
        // Update all the sprites
		for (const sprite of this.sprites) {
			sprite.update(elapsed_time);
		}
        this.last_update_time = now;
	}

	onleftclick(x, y) {
		this.avatar.onleftclick(x, y);
	}

    onrightclick(x, y) {
		this.avatar.onrightclick(x, y);
    }

	async loadImages() {
		try{
			const response = await fetch('getImages', {
				method: 'POST',
				cache: 'no-cache',
				headers: {
					'Content-Type': 'application/json',
				},
			});
			const data = await response.json();
			this.map = data;
		} catch(error) {
			console.error('Error:', error);
		}
		for(let key in this.map) {
			let img = new Image();
			img.src = 'images/' + this.map[key].file
			let sprite = new Sprite(this.map[key].x, this.map[key].y, img.src);
			sprite.type = this.map[key].file;
			this.sprites.push(sprite);
		};
	}
}




class View
{
	constructor(model) {
		this.model = model;
		this.canvas = document.getElementById("myCanvas");
		console.log("Got the canvis");
	}

	update() {
		// Move the camera to where the robot is
		this.model.scroll_x = this.model.avatar.x - 500;
		this.model.scroll_y = this.model.avatar.y - 250;


        // Clear the screen
		let ctx = this.canvas.getContext("2d");
		ctx.fillStyle = "tan";
		ctx.fillRect(0, 0, 1000, 500);
		ctx.fillStyle = "black";
        // Sort the sprites by their y-value to create a pseudo-3D effect
        this.model.sprites.sort((a,b) => a.y - b.y );

        // Draw all the sprites
		for (const sprite of this.model.sprites) {
			/*if(sprite.type === "robot" || sprite.type === "fireball")
			{
				ctx.drawImage(sprite.image, sprite.x - sprite.image.width / 2, sprite.y - sprite.image.height);
			}
			else*/
			ctx.drawImage(sprite.image, sprite.x - sprite.image.width / 2 - this.model.scroll_x, sprite.y - sprite.image.height - this.model.scroll_y);
			if(sprite.type === "robot")
				ctx.fillText(sprite.name, sprite.x - sprite.image.width / 2 - this.model.scroll_x, sprite.y - sprite.image.height - 10 -this.model.scroll_y);
		}
	}

}




class Controller
{
	constructor(model, view) {
		this.model = model;
		this.view = view;
		let self = this;

        // Add event listeners
		view.canvas.addEventListener("click", function(event) { self.onLeftClick(event); return false; });
		view.canvas.addEventListener("contextmenu", function(event) { self.onRightClick(event); return false; });

		window.addEventListener("keydown", function(event) { 
			self.onKeyDown(event);
		});
	}

	async onLeftClick(event) {
        event.preventDefault(); 
		const x = event.pageX - this.view.canvas.offsetLeft;
		const y = event.pageY - this.view.canvas.offsetTop;
		this.model.onleftclick(x+this.model.scroll_x, y+this.model.scroll_y);
		// send id, time-stamp, coordinates of mouse, coordinates of robot
        // DONE: tell the server about this click
		try {
			const response = await fetch('ajax', {
			method: 'POST',
			cached: 'no-cache',
			headers: {
				'Content-Type': 'application/json',
			},
			body: JSON.stringify({id: id, x: x+this.model.scroll_x, y: y+this.model.scroll_y, click_x: this.model.avatar.x, click_y: this.model.avatar.y, time: this.model.last_update_time, type: "robot", name: this.model.avatar.name}),
		});
		const text = await response.text();
		console.log(`The server replied: ${text}`);
		} catch(error) {
			console.error('Error:', error);
		}
	}

    async onRightClick(event) {
        event.preventDefault(); // Suppress the context menu
		const x = event.pageX - this.view.canvas.offsetLeft;
		const y = event.pageY - this.view.canvas.offsetTop;
		this.model.onrightclick(x+this.model.scroll_x, y+this.model.scroll_y);
        // DONE: tell the server about this click
		try {
			const response = await fetch('ajax', {
			method: 'POST',
			cached: 'no-cache',
			headers: {
				'Content-Type': 'application/json',
			},
			body: JSON.stringify({id: id, x: x+this.model.scroll_x, y: y+this.model.scroll_y, click_x: this.model.avatar.x, click_y: this.model.avatar.y, time: this.model.last_update_time, type: "fireball"}),
		});
		const text = await response.text();
		console.log(`The server replied: ${text}`);
		} catch(error) {
			console.error('Error:', error);
		}
    }

	/*
	onKeyDown(event) {
		if(event.key == "ArrowRight") {
			//this.model.avatar.x += 10;
			this.model.scroll_x += 10;
		}
		else if(event.key == "ArrowLeft") {
			//this.model.avatar.x -= 10;
			this.model.scroll_x -= 10;
		}
		else if(event.key == "ArrowUp") {
			//this.model.avatar.y -= 10;
			this.model.scroll_y -= 10;
		}
		else if(event.key == "ArrowDown") {
			//this.model.avatar.y += 10;
			this.model.scroll_y += 10;
		}
	}
	*/
	parseISOString = (s) => {
		let b = s.split(/\D+/);
		return new Date(Date.UTC(b[0], --b[1], b[2], b[3], b[4], b[5], b[6]));
	}

	process(data) {
		//loops through all robot objects in data["left"] from server
		Object.keys(data).forEach(iterator_id => {
			//make a current_sprite object
			let current_sprite = data[iterator_id];
			//if the robot is the same as the avatar, return
			if(current_sprite.id == id || current_sprite.id == undefined)
				return;
			//go through all sprites in the model, compare id's of this.model.sprites[i] and current_sprite
			let sprite = this.model.sprites.find(sprite => sprite.id == current_sprite.id);
			//if sprite is not found, create a new sprite
			if(!sprite)
			{
				sprite = new Sprite(current_sprite.click_x, current_sprite.click_y, "robot.png");
				sprite.id = current_sprite.id;
				sprite.name = current_sprite.name;
				sprite.update = Sprite.prototype.update_travel;
				this.model.sprites.push(sprite);
			}
			if(current_sprite.type == "robot")
			{
				//update sprite
				sprite.type = "robot";
				sprite.onclick_set_destination(current_sprite.x, current_sprite.y);
			}
			else if(current_sprite.type == "fireball")
			{
				if(!this.model.fireball_ids.includes(iterator_id))
				{
					sprite.type = "fireball";
					//throw fireball
					sprite.onclick_throw_fireball(current_sprite.x, current_sprite.y, iterator_id);
					this.model.fireball_ids.push(iterator_id);
				}
			}
		});
	}

	scoreSort(data) {
		let sortable = [];
		for(let name in data)
		{
			sortable.push([name, data[name]]);
		}
		sortable.sort(function(a, b) {
			return b[1] - a[1];
		});
		let el = document.getElementById("scores");
		el.innerHTML = "";
		for(let i = 0; i < sortable.length; i++)
		{
			el.innerHTML += `${sortable[i][0]}: ${sortable[i][1]}<br>`;
		}
	}


	async update() {
        // Ensure we do not hammer the server with too many update requests
        let now = new Date();
        if (now - last_update_time > 500) { // miliseconds
            last_update_time = now;
            // DONE: request updates from the server here
			try{
				const response = await fetch('update', {
					method: 'POST',
					cache: 'no-cache',
					headers: {
						'Content-Type': 'application/json',
					},
					body: JSON.stringify({score: score, name: this.model.avatar.name}),
				});
				const data = await response.json();
				//robot process
				this.process(data["left"]);
				//fireball process
				this.process(data["right"]);
				//score sort
				this.scoreSort(data["scores"]);

			} catch(error) {
				console.error('Error:', error);
			}
			this.model.last_update_time = now;
        }

	}

}




class Game {
	constructor(name) {
		this.model = new Model(name);
		this.view = new View(this.model);
		this.controller = new Controller(this.model, this.view);
	}

	onTimer() {
		this.controller.update();
		this.model.update();
		this.view.update();
	}
}

function submitName() {
	const name = document.getElementById('name').value;
	const textbox = document.getElementById('textbox');
	textbox.style.display = 'none';
	const canvas = document.getElementById('myCanvas');
	canvas.style.display = 'block';

	game = new Game(name);
	let timer = setInterval(() => { game.onTimer(); }, 30);
}

