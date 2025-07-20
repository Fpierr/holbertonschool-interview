#!/usr/bin/node

const fetch = require('node-fetch');

const id = process.argv[2];
if (!id) {
  console.error('Usage: ./0-starwars_characters.js <movie_id>');
  process.exit(1);
}

async function main() {
  try {
    const res = await fetch(`https://swapi-api.hbtn.io/api/films/${id}/`);
    const film = await res.json();

    for (const url of film.characters) {
      const resChar = await fetch(url);
      const character = await resChar.json();
      console.log(character.name);
    }
  } catch (error) {
    console.error('Error:', error.message);
  }
}

main();

