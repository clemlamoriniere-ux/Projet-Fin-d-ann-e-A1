let echelle = 2000000000;
let a = 0;
let button;
let planetes = [];
const couleurParNom = {
  venus: [100, 80, 40],
  venus_asym: [255, 220, 150],
  terre: [250, 250, 250],
  terre_asym: [70, 130, 200],
  mars: [80, 30, 15],
  mars_asym: [200, 100, 60],
  jupiter: [90, 70, 45],
  jupiter_asym: [220, 185, 140],
};

function readFile(input) {
  for (let file of input.files) {
    let reader = new FileReader();

    reader.readAsText(file);

    reader.onload = function () {
      let dataJSON = JSON.parse(reader.result);
      let method = Object.keys(dataJSON)[0];

      planetes.push({
        traj: dataJSON[method],
        couleur: couleurParNom[
          file.name.replace(".json", "").toLowerCase()
        ] || [255, 255, 255],
        historique: [],
      });
      background(0);
      redraw();
    };
  }

  reader.onerror = function () {
    console.log(reader.error);
  };
}

function preload() {
  button = createButton("reset");
  button.mousePressed(reset);
}

function reset() {
  a = 0;
  planetes = [];
  background(0);
  redraw();
}

function mousePressed() {
  if (mouseButton === LEFT) {
    loop();
  }
}

function mouseReleased() {
  noLoop();
}

function setup() {
  noLoop();
  createCanvas(1600, 900);
  background(0);
  a = 0;
}

function draw() {
  background(0);

  noStroke();
  fill(255, 255, 0);
  circle(width / 2, height / 2, 30);

  for (let p of planetes) {
    let [r, g, b] = p.couleur;
    noStroke();
    fill(r, g, b);
    for (let pos of p.historique) {
      circle(pos[0], pos[1], 3);
    }
  }
  for (let p of planetes) {
    let idx = a % p.traj.length;
    let [r, g, b] = p.couleur;
    let x = width / 2 + p.traj[idx][0][0] / echelle;
    let y = height / 2 + p.traj[idx][0][1] / echelle;

    p.historique.push([x, y]);

    fill(r, g, b);
    noStroke();
    circle(x, y, 10);
  }

  a = a + 7;
}
