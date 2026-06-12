let echelle = 1000000000;
let reader = new FileReader();
let file;
let dataJSON;
let method;
let trajectoireVisitee = [];

function readFile(input) {
  let file = input.files[0];

  let reader = new FileReader();

  reader.readAsText(file);

  reader.onload = function () {
    dataJSON = JSON.parse(reader.result);
    method = Object.keys(dataJSON)[0];
    a = 0;
    trajectoireVisitee = [];

    console.log(dataJSON[method]);
    for (let i = 0; i < 3750; i++) {
      point(
        width / 2 + dataJSON[method][i][0][0] / echelle,
        height / 2 + dataJSON[method][i][0][1] / echelle,
      );
      i++;
    }
    stroke(255, 0, 0);
    fill(0, 100, 200);
    circle(
      width / 2 + dataJSON[method][0][0][0] / echelle,
      height / 2 + dataJSON[method][0][0][1] / echelle,
      10,
    );
  };

  reader.onerror = function () {
    console.log(reader.error);
  };
}

function mousePressed() {
  if (mouseButton === LEFT) {
    loop();
  }
}

function mouseReleased() {
  noLoop();
}

function windowResized() {
  createCanvas(windowWidth, windowHeight - 150);
}

function setup() {
  noLoop();
  createCanvas(1380, 720);
  stroke(255, 255, 0);
  fill(255, 255, 0);
  circle(width / 2, height / 2, 30);
  a = 0;
}

function draw() {
  background(0);

  stroke(255, 255, 255);
  for (let i = 0; i < trajectoireVisitee.length; i++) {
    point(trajectoireVisitee[i].x, trajectoireVisitee[i].y);
  }

  stroke(255, 255, 0);
  fill(255, 255, 0);
  circle(width / 2, height / 2, 30);

  let px = width / 2 + dataJSON[method][a][0][0] / echelle;
  let py = height / 2 + dataJSON[method][a][0][1] / echelle;

  // Ajoute la position actuelle à la trajectoire
  trajectoireVisitee.push({ x: px, y: py });

  stroke(255, 0, 0);
  fill(0, 100, 200);
  circle(px, py, 10);

  if (a < 36501) {
    a = a + 5;
  } else {
    a = 0;
  } // repart au début sans effacer la trajectoire
}
