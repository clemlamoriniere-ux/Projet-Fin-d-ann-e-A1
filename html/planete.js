let echelle = 600000000;
let dataJSON;
let method;
let a = 0;
let enCours = false;
let etoiles = [];

function readFile(input) {
  let file = input.files[0];
  let reader = new FileReader();

  reader.readAsText(file);

  reader.onload = function () {
    dataJSON = JSON.parse(reader.result);
    method = Object.keys(dataJSON)[0];
    redraw();
  };

  reader.onerror = function () {
    console.log(reader.error);
  };
}

function toggleAnim() {
  if (enCours) {
    noLoop();
    enCours = false;
  } else {
    loop();
    enCours = true;
  }
}

function resetAnim() {
  a = 0;
  noLoop();
  enCours = false;
}

function setup() {
  noLoop();
  let canvas = createCanvas(1100, 600);
  canvas.parent("canvas-container");
  a = 0;
  for (let i = 0; i < 200; i++) {
    etoiles.push({ x: random(width), y: random(height), taille: random(1, 3) });
  }
}

function draw() {
  background(0);

  noStroke();
  fill(255, 255, 255);
  for (let i = 0; i < etoiles.length; i++) {
    circle(etoiles[i].x, etoiles[i].y, etoiles[i].taille);
  }

  if (dataJSON) {
    stroke(255, 255, 255);
    for (let i = 0; i < 3750; i++) {
      point(
        550 + dataJSON[method][i][0][0] / echelle,
        300 + dataJSON[method][i][0][1] / echelle,
      );
      i++;
    }
  }

  stroke(255, 255, 0);
  fill(255, 255, 0);
  circle(550, 300, 60);

  if (dataJSON) {
    stroke(255, 0, 0);
    fill(210, 210, 220);
    circle(
      550 + dataJSON[method][a][0][0] / echelle,
      300 + dataJSON[method][a][0][1] / echelle,
      20,
    );

    if (a < 36501) {
      a = a + 1;
    } else {
      a = 0;
    }
  }
}
