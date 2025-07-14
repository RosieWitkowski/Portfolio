document.addEventListener("DOMContentLoaded", function({
    alert("DONE");
    document.querySelector("#diamondsButton").onclick = function(){
        alert("PRESS");
        let diamondsMined = document.querySelector('#diamondsMined');
        let possible = 2
        if (possible == 2)
        {
            diamondsMined.innerHTML = diamondsMined + 1;
        }
    }
}));
