const express = require("express");
const multer = require("multer");
const bodyParser = require("body-parser");
const app = express();

app.use(bodyParser.urlencoded({ extended: true }));

//-----------------------------------------------------------------
// SET STORAGE
var storage = multer.diskStorage({
  destination: function (req, file, cb) {
    cb(null, "uploads");
  },
  filename: function (req, file, cb) {
    cb(null, file.originalname);
  },
});

var upload = multer({ storage: storage });
// var upload = multer({ dest: "uploads/" });
//------------------------------------------------------------------
app.post("/upload", upload.single("myFile"), (req, res, next) => {
  const file = req.file;
  if (!file) {
    res.status(400);
    res.json({ success: false, msg: "please add a file" });
  } else {
    res.send(file);
  }
});

app.listen(3000, () => console.log("Server started on port 3000"));
