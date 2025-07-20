#!/usr/bin/node

const https = require('https')

const id = process.argv[2]
if (!id) return console.error('Usage: ./0-starwars_characters.js <movie_id>')

function fetch(url) {
    return new Promise(resolve=> {
        https.get(url, res= > {
            let data = ''
            res.on('data', chunk=> (data += chunk))
            res.on('end', ()= > resolve(JSON.parse(data)))
        })
    })
}

fetch(`https: // swapi-api.hbtn.io/api/films /${id} /`)
.then(film=> film.characters.reduce((p, url) = >
                                     p.then(() = > fetch(url).then(c = > console.log(c.name))),
                                     Promise.resolve()
                                     ))
