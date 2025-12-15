function mudarCor(novaCor) {
    document.body.style.backgroundColor = novaCor;

    var lua = document.getElementById('lua');
    var sol = document.getElementById('sol');
    
    if (novaCor === 'black') {
        lua.style.display = 'none';
        sol.style.display = 'block';
        document.body.style.color = 'white';
    } else {
        lua.style.display = 'block';
        sol.style.display = 'none';
        document.body.style.color = '#212529';
    }
}