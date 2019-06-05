function MD() {
	this.table = null;
	this.object = null;

}

/* -Form pentru date- */
MD.prototype.CreazaMatriceaDeIncidenta = function(m, n) {
	this.table = document.createElement("table");
	for(var i=0;i<=m;i++)for(var row=this.table.insertRow(-1),j=0;j<=n;j++)row.insertCell(-1).innerHTML=i&&j?"<input onfocus=\"this.select()\" id='"+i+":"+j+"' value=\"0\"/>":i?"u<sub>"+i+"</sub>":j?"x<sub>"+j+"</sub>":" ";
};
MD.prototype.CreazaMatriceaDeAdiacenta = function(n) {
	this.table = document.createElement("table");
	for(var i=0;i<=n;i++)for(var row=this.table.insertRow(-1),j=0;j<=n;j++)row.insertCell(-1).innerHTML=i&&j?"<input onfocus=\"this.select()\" id='"+i+":"+j+"' value=\"0\"/>":i?"x<sub>"+i+"</sub>":j?"x<sub>"+j+"</sub>":" ";
};

MD.prototype.CreazaListaDeAdiacenta = function() {
	var table = this.table = document.createElement("table");
	this.table.insertRow(-1).innerHTML = "<tr><td style=\"width: 20px\"></td><td></td></tr>";
	this.table.insertRow(-1).innerHTML = "<tr><td>1</td><td><input onfocus=\"this.select()\" style=\"border: none; width: 600px\"></td></tr>";
	this.table.onkeyup = function(evt) {
		if (evt.target.tagName == "INPUT") {
			var p = evt.target.parentElement.parentElement.previousSibling;
	    var n = evt.target.parentElement.parentElement.nextSibling;
			if ((evt = evt || window.event).keyCode == 13) {
	      if (!n) {
	        var row = table.insertRow(-1);
	        var ID = parseInt(row.previousSibling.children[0].innerHTML);
	        row.insertCell(-1).innerHTML = '<input onfocus=\"this.select()\" id="'+(ID+1)+'" style="border: none; width: 600px">';
	        row.insertCell(0).innerHTML = (ID+1);
	        row.children[1].children[0].select();
	        row.children[1].children[0].scrollIntoView();
	      } else {
	      	n.children[1].children[0].select();
	      	n.children[1].children[0].scrollIntoView();
	      }
	    }
	    if (evt.keyCode == 8) {
	      if (!evt.target.value) {
	        if (p.children[1].children[0]) {
	        	var v = parseInt(evt.target.parentElement.parentElement.children[0].innerHTML), e, l = table.getElementsByTagName("input");
					  for (var i = 0; i < l.length; i++) { 
					  	e = l[i].value.trim().replace(/  +/g,' ').split(' ');
					  	for (var j = 0; j < e.length; j++) {
					  		if (parseInt(e[j]) > v){
					 	 			e[j] = parseInt(e[j])-1
					 	 		} else if (parseInt(e[j]) == v) {
					 	 			e[j] = " ";
					 	 		}					  		 		
					  	}
					  	l[i].value = e.join(" ").replace(/  +/g,' ').trim()
					  }
	        	(p.children[1].children[0]||{}).select()
	        	evt.target.parentElement.parentElement.remove()       	
	        	do {
	        		n.children[0].innerHTML = parseInt(n.children[0].innerHTML)-1
						} while (n = n.nextSibling);
	        }
	      }
	    }
		}
	}
};


/* -Citirea Datelor- */
MD.prototype.CitesteMatriceaDeAdiacenta = function(){
  this.object = new Object();
  var e, l = this.table.getElementsByTagName("tr");
  for (var i = 1; i < l.length; i++) { 
    this.object[i] = new Array();
    e = l[i].getElementsByTagName("input");
    for (var j = 0; j < e.length; j++) { 
    	if (e[j].value == 1) {
    		this.object[i].push(j+1)
    	}
  	}
  }
}
MD.prototype.CitesteMatriceaDeIncidenta = function(){
  this.object = new Object();
  var s, f, e, l = this.table.getElementsByTagName("tr");
 	for (var i = 1; i < this.table.rows[0].cells.length; i++) this.object[i] = new Array();
  for (var i = 1; i < l.length; i++) { 
  	s=null; f=null; e = l[i].getElementsByTagName("input");
    for (var j = 0; j < e.length; j++) { 
    	if (e[j].value == -1) s = j+1;
    	if (e[j].value == 1) f = j+1;
    	if (e[j].value == 2) { this.object[j+1].push(j+1); break }
    	if (s && f) { this.object[s].push(f); break }
  	}
  }
}
MD.prototype.CitesteListaDeAdiacenta = function(){
	this.object = new Object();
	var e, l = this.table.getElementsByTagName("input");
	for (var i = 1; i < this.table.rows.length; i++) this.object[i] = new Array();
  for (var i = 0; i < l.length; i++) { 
  	e = l[i].value.trim().replace(/  +/g,' ').split(' ');
  	for (var j = 0; j < e.length; j++) {
  		if (parseInt(e[j]) && this.object[e[j]]) {
  			if (e[j]==0) {
  				break;
  			} else {
  				this.object[i+1].push(parseInt(e[j]))
  			}
  		}  		
  	}
  }
}

/* -Afisarea Datelor- */
MD.prototype.AfiseazaMatriceaDeAdiacenta = function(){
	this.CreazaMatriceaDeAdiacenta(Object.keys(this.object).length)
	for (var i in this.object) {
    for (var j = 0; j < this.object[i].length; j++) {
     	this.table.rows[i].cells[this.object[i][j]].children[0].value = 1;
    }
  }    
}
MD.prototype.AfiseazaMatriceaDeIncidenta = function(){
	var c=1,m=0;
	for (var i in this.object) { m+=this.object[i].length }
	this.CreazaMatriceaDeIncidenta(m,Object.keys(this.object).length)
	for (var i in this.object) {
    for (var j = 0; j < this.object[i].length; j++) {
    	if (this.object[i][j] == i) {
    		this.table.rows[c].cells[this.object[i][j]].children[0].value = 2;
    	} else {
    		this.table.rows[c].cells[i].children[0].value = -1;
    		this.table.rows[c].cells[this.object[i][j]].children[0].value = 1;
    	}
     	c++;
    }
  }    
}
MD.prototype.AfiseazaListaDeAdiacenta = function(){
	this.CreazaListaDeAdiacenta()
	for (var i in this.object) {
		if (!this.table.rows[i]) {
			var row = this.table.insertRow(-1);
			row.insertCell(-1).innerHTML = '<input onfocus=\"this.select()\" style="border: none; width: 600px">';
			row.insertCell(0).innerHTML = i;
		}
    this.table.rows[i].cells[1].children[0].value = (this.object[i].join(" ") + " 0").trim();
  }
}
/*Dropdown Menu 1 and 2*/
$(document).ready(function() {
	$("#dropdown_menu1").click(function() {
		var menu1 = document.getElementById('first_menu');
		$("#first_menu").css({"left": (menu1.style.left < 0+"%") ? "0%" : "-150%"});
		$("#second_menu").css({"left": "-150%"});
	});
	$("#dropdown_menu2").click(function() {
		var menu2 = document.getElementById('second_menu');
		$("#second_menu").css({"left": (menu2.style.left < 0+"%") ? "0%" : "-150%"});
		$("#first_menu").css({"left": "-150%"});
	});
});