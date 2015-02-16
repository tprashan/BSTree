var Edges={
	"BLR" : ["CHN","DEL"],
	"CHN" : ["BLR"],
	"MUM" : ["DEL","KOL"],
	"KOL" : ["MUM","DEL","PUNE"],
	"DEL" : ["BLR","MUM","KOL"],
	"PUNE": ["LCK"],
	"LCK" : ["KNP"],
	"KNP" : ["LCK"]
};
var isDirectPath=function(src,des){
	var edges=Edges[src];
	return edges.indexOf(des)>-1;
};
var findPath=function(path,src,des){
	var pathFound=[];
	var links=Edges[src];
	if(isDirectPath(src,des)){
		path.push(src);	path.push(des);
		return path;
	}
	if(path.indexOf(src)>-1) return [];
	path.push(src);
	// console.log("------------",links);
	console.log(path);

	for(var i=0;i<links.length;i++){
		pathFound=findPath(path,links[i],des);
		// console.log(".............",pathFound);
		if(pathFound.length>0) return pathFound;
	}
	// links.forEach(function(link){
	// 	pathFound=findPath(path,link,des);
	// 	console.log(".............",pathFound);
	// 	if(pathFound.length>0) return pathFound;
	// });
	return pathFound;
};
console.log(findPath([],process.argv[2],process.argv[3]));