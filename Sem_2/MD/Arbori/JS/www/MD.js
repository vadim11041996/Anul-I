"use strict";

var MD = (function(){
	var M = [];
	return {
		MA: function(a){
			if (a) {
				M = []
				for (var i = 0, n = (a||[]).length; i < n; i++){
					M[i+1]=[]
					for (var j = 0; j < n; j++) if ((a[i]||[])[j] > 0) M[i+1][j+1]=a[i][j]
				}
			}else{
				for (var i = 0, Data = [], n = M.length-1; i < n; i++) {
			  	Data[i] = []
			  	for (var j = 0; j < n; j++) Data[i][j] = M[i+1][j+1] | 0
				}
				return Data
			}
		},
		//Parcurge în adâncime
		PA: function(s){
			var S=[],L=[]
			PA(s)
			for(var i=1,n=M.length;n>i;i++) PA(i)
			return L
			function PA(i) {
				if (!S[i]) {
					S[i] = 1; L.push(i)
					for(var j=1,n=(M[i]||[]).length;n>j;j++)M[i][j]&&PA(j)
				}
			}
		},
		//Parcurge în lăţime
		PL: function(s){
			var L = [], S = []
			PL(s)
			for(var i=1,n=M.length;n>i;i++) PL(i)
			return L
			function PL(l){
				var A_1 = [], A_2 = []
				if (!S[l]) A_1 = [l];
				while(1){
					for (var i = 0, n = A_1.length; i < n; i++) {
						if (!S[A_1[i]]) { S[A_1[i]] = 1; L.push(A_1[i]) 
							for (var j = 1, k = M[A_1[i]].length; j < k; j++) {
								if (M[A_1[i]][j]) A_2.push(j)
							}
						}
					}
					if (A_2.length == 0) break;		
					A_1 = A_2; A_2 = []
				}
			}
			return L;	
		}
	}	
})();

function CTable(x,y){	
	for (var i = 0, Data = [],HTML = ""; i <= x; i++) {
		Data[i-1] = []
		HTML += "<tr>"
		for (var j = 0; j <= y; j++) {
			Data[i-1][j-1] = 0
			HTML += "<td>"+(i&&j ? "<input name="+(i-1)+"|"+(j-1)+" onclick='this.select()' value=0 />" : "x<sub>" + (!i?j:i) + "</sub>")+"</td>"
		}
		HTML += "</tr>"
	}
	return [HTML,Data]
}

onmessage = function(d){
	switch(d.data[0]){
		case "CTable":
			postMessage([d.data[0],CTable(d.data[1][0],d.data[1][0])])
			break;
		case "Calc":
			var Min = [], Max = [];
			MD.MA(d.data[1][0])
			postMessage([d.data[0],[MD.PA(d.data[1][1]).join(", "), MD.PL(d.data[1][1]).join(", ")]])
			break;
	}
}