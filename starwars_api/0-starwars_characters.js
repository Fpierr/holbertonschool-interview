#!/usr/bin/node

const request = require('request');
const id = process.argv[2];

if (!id) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

const filmUrl = `https://swapi-api.hbtn.io/api/films/${id}/`;

request(filmUrl, (err, res, body) => {
  if (err) {
    console.error(err);
    return;
  }

  const film = JSON.parse(body);
  const characters = film.characters;

  function printCharacter (index) {
    if (index >= characters.length) return;

    request(characters[index], (err, res, body) => {
      if (!err) {
        const character = JSON.parse(body);
        console.log(character.name);
        printCharacter(index + 1);
      }
    });
  }

  printCharacter(0);
});
