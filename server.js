
const http = require("http");
const fs = require("fs");
const images = 'images';

const host = '127.0.0.1';
const port = 8080;
let left = {};
let right = {};
let map = {};
let scores = {};

const some_mime_types = {
    '.html': 'text/html',
    '.ico': 'image/png',
    '.jpeg': 'image/jpeg',
    '.jpg': 'image/jpeg',
    '.js': 'text/javascript',
    '.png': 'image/png',
    '.svg': 'image/svg+xml',
    '.zip': 'application/zip',
}

const requestListener = (request, response) => {
    //get parts of request in stream
    let body = '';
    request.on('data', (chunk) => {
      body += chunk;
    });
    //when request is done, do this
    request.on('end', () => {
      let filename = request.url.substring(1); // cut off the '/'
      if (filename.length === 0)
        filename = 'client.html';
      const last_dot = filename.lastIndexOf('.');
      const extension = last_dot >= 0 ? filename.substring(last_dot) : '';
      if (filename === 'getImages') {
          fs.readdir(images, (err, files) => {
            if (err) {
                return console.log('Unable to scan directory: ' + err);
            }
            // List all files in the directory
            let i = 0;
            if(Object.keys(map).length === 0)
            {
              files.forEach((file) => {
                  map[i] = {file: file, x: Math.random() * 10000 % 1000, y: Math.random() * 10000 % 500};
                  i++;
              });
            }
            response.setHeader('Content-Type', 'application/json');
            response.writeHead(200);
            response.end(JSON.stringify(map));
          });    
      } else if (filename === 'ajax') {
        const data = JSON.parse(body);
        if(data.type === "robot")
        {
          left[data.id] = data;
        }
        else if(data.type === "fireball")
        {
          let id = Math.floor(Math.random() * 10000000);
          right[id] = data;
          scores[data.name] = data.score;
        }
        response.writeHead(200);
        response.end("OK");
      } else if (filename === 'update') {
        const packet = JSON.parse(body);
        scores[packet.name] = packet.score;
        response.setHeader('Content-Type', 'application/json');
        response.writeHead(200);
        let data = {left: left, right: right, scores: scores};
        response.end(JSON.stringify(data));
      } 
      else if (extension in some_mime_types && fs.existsSync(filename)) {
          fs.readFile(filename, null, (err, data) => {
              response.setHeader("Content-Type", some_mime_types[extension]);
              response.writeHead(200);
              response.end(data);
          });
      } else {
          response.setHeader("Content-Type", "text/html");
          response.writeHead(404);
          response.end(`<html><body><h1>404 - Not found</h1><p>There is no file named "${filename}".</body></html>`);
      }
    });
};

const server = http.createServer(requestListener);
server.listen(port, host, () => {
    console.log(`Server is running on http://${host}:${port}`);
});