const express = require('express');
const path = require('path');
const app = express();
const port = 3000;

// Serve converter.html when someone visits the root URL
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'converter.html'));
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});
