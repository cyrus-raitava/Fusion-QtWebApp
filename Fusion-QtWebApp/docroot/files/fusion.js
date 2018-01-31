function loadElements()
{
  var subTitle = document.createElement("h2");
  subTitle.id = "subTitle";

  subTitle.innerHTML = "It works!";
  document.body.appendChild(subTitle);

  var currentSourceID = document.createElement("h3");
  currentSourceID.id = "currentSourceID";
  currentSourceID.innerHTML = "The current source ID is: ";
  document.body.appendChild(currentSourceID);

  var flags = document.createElement("h3");
  flags.id = "flags";
  flags.innerHTML = "The current flag(s) are: ";
  document.body.appendChild(flags);

  var model = document.createElement("h3");
  model.id = "model";
  model.innerHTML = "The model is: ";
  document.body.appendChild(model);

  var name = document.createElement("h3");
  name.id = "name";
  name.innerHTML = "The current name is: ";
  document.body.appendChild(name);

  var nameSize = document.createElement("h3");
  nameSize.id = "nameSize";
  nameSize.innerHTML = "The name size is: ";
  document.body.appendChild(nameSize);

  var sourceID = document.createElement("h3");
  sourceID.id = "sourceID";
  sourceID.innerHTML = "The source ID is: ";
  document.body.appendChild(sourceID);

  var sourceType = document.createElement("h3");
  sourceType.id = "sourceType";
  sourceType.innerHTML = "The current source type is: ";
  document.body.appendChild(sourceType);

}
