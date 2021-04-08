#!/usr/bin/node
const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv.slice(2)[0];
request({ url: url, method: 'GET' },
  async function (error, response, body) {
    if (error) {
      console.log(error);
    } else {
      const info = JSON.parse(body);
      for (let i = 0; i < info.characters.length; i++) {
        await new Promise(function (resolve, reject) {
          request({ url: info.characters[i], method: 'GET' },
            function (charError, charResponse, charBody) {
              if (charError) {
                console.log(charError);
              } else {
                const charInfo = JSON.parse(charBody);
                console.log(charInfo.name);
              }
              resolve();
            });
        });
      }
    }
  });
