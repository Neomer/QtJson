# QtJson
Alternative module for working with Json in Qt.

Tool helps you to create a Json object and simply use it in your own way.


Sample of usage:

	d->root()["qwqw"]["3443"] = 34;
	d->root()["334"] = true;
	d->root()["array"] = 4;
	d->root()["array"] += 5;
	d->root()["array"] += 6;
	d->root()["array"] += "4556";

JSON representation:

{
	"qwqw": {
		"3443": 34
	},
	"334": true,
	"array": [4,5,6,"4556"]
}
