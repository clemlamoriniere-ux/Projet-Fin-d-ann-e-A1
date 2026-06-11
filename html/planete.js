let echelle = 600000000;
let dataJSON;
let method;
let a = 0;
let button;

function readFile(input) {
  let file = input.files[0];
  let reader = new FileReader();

  reader.readAsText(file);

  reader.onload = function () {
    dataJSON = JSON.parse(reader.result);
    method = Object.keys(dataJSON)[0];

    console.log(dataJSON[method]);
    stroke(255, 255, 255);
    for (let i = 0; i < 3750; i++) {
      point(
        550 + dataJSON[method][i][0][0] / echelle,
        300 + dataJSON[method][i][0][1] / echelle,
      );
      i++;
    }
    stroke(255, 0, 0);
    fill(0, 100, 200);
    circle(
      550 + dataJSON[method][0][0][0] / echelle,
      300 + dataJSON[method][0][0][1] / echelle,
      20,
    );
  };

  reader.onerror = function () {
    console.log(reader.error);
  };
}

function preload() {
  button = createButton("reset");
  button.mousePressed(resetAnim);
}

function resetAnim() {
  a = 0;
  loop();
  noLoop();
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
  let canvas = createCanvas(1100, 600);
  canvas.parent("canvas-container");
  stroke(255, 255, 0);
  fill(255, 255, 0);
  circle(550, 300, 60);
  a = 0;
}

function draw() {
  background(0);

  stroke(255, 255, 255);
  for (let i = 0; i < 3750; i++) {
    point(
      550 + dataJSON[method][i][0][0] / echelle,
      300 + dataJSON[method][i][0][1] / echelle,
    );
    i++;
  }

  stroke(255, 255, 0);
  fill(255, 255, 0);
  circle(550, 300, 60);

  stroke(255, 0, 0);
  fill(0, 100, 200);
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
