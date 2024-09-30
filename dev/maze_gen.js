import mazeGen from '@sbj42/maze-generator';
import fs from 'fs';
import { PNG } from 'pngjs';

const size = 10;
const pixelSize = 10;
const mazePNG = new PNG({
    width: size * pixelSize,
    height: size * pixelSize,
    colorType: 2
});

for (let y = 0; y < mazePNG.height; y++) {
    for (let x = 0; x < mazePNG.width; x++) {
        let idx = (mazePNG.width * y + x) * 4;

        mazePNG.data[idx] = 255;
        mazePNG.data[idx + 1] = 255;
        mazePNG.data[idx + 2] = 255;
        mazePNG.data[idx + 3] = 255;
    }
}

const maze = mazeGen.generate(size, size, {
    generator: '@sbj42/maze-generator-backtrack'
});

let content = 'MAP_DATA\n';
for (let y = 0; y < size; y++) {
    for (let x = 0; x < size; x++) {
        const index = (y * size + x); 

        const cell = maze.cell(x, y);
        let directionLine = '';
        let directionCount = (cell.north() + cell.south() + cell.east() + cell.west());
        if (cell.north()) directionLine += `north:${(y - 1) * size + x} `;
        if (cell.south()) directionLine += `south:${(y + 1) * size + x} `;
        if (cell.east()) directionLine += `east:${y * size + (x + 1)} `;
        if (cell.west()) directionLine += `west:${y * size + (x - 1)} `;

        content += index + '\n';
        if (index == 90) {
            content += `The Start of The Maze\n`;
            content += 'You are in a maze that continues in all directions. You see all sorts of pathways, but everything seems so uniform...\n';
        } else if (index == 9) {
            content += `The End of The Maze\n`;
            content += 'You finally see the exit, with a pathway towards an impressive looking castle...\n';
        } else if (directionCount == 1) {
            content += `A Dead End of The Maze\n`;
            content += 'You look around a see that you have nowhere else forward, so you must turn around...\n';
        } else {
            content += `The Maze\n`;
            content += 'You are in still in a maze that continues in all directions. The walls are uniform and repeating...\n';
        }

        content += directionLine.trimEnd() + '\n\n';

        if (!cell.north()) {
            for (let j = 0; j < pixelSize; j++) {
                let idx = (mazePNG.width * (y * pixelSize) + ((x * pixelSize) + j)) * 4;

                mazePNG.data[idx] = 0;
                mazePNG.data[idx + 1] = 0;
                mazePNG.data[idx + 2] = 0;
                mazePNG.data[idx + 3] = 255;
            }
        }
        if (!cell.south()) {
            for (let j = 0; j < pixelSize; j++) {
                let idx = (mazePNG.width * (y * pixelSize + 9) + ((x * pixelSize) + j)) * 4;

                mazePNG.data[idx] = 0;
                mazePNG.data[idx + 1] = 0;
                mazePNG.data[idx + 2] = 0;
                mazePNG.data[idx + 3] = 255;
            }
        }
        if (!cell.east()) {
            for (let j = 0; j < pixelSize; j++) {
                let idx = (mazePNG.width * (y * pixelSize + j) + (x * pixelSize + 9)) * 4;

                mazePNG.data[idx] = 0;
                mazePNG.data[idx + 1] = 0;
                mazePNG.data[idx + 2] = 0;
                mazePNG.data[idx + 3] = 255;
            }
        }
        if (!cell.west()) {
            for (let j = 0; j < pixelSize; j++) {
                let idx = (mazePNG.width * (y * pixelSize + j) + (x * pixelSize)) * 4;

                mazePNG.data[idx] = 0;
                mazePNG.data[idx + 1] = 0;
                mazePNG.data[idx + 2] = 0;
                mazePNG.data[idx + 3] = 255;
            }
        }
    }
}

fs.writeFileSync('map.txt', content);
mazePNG.pack().pipe(fs.createWriteStream(`maze.png`));