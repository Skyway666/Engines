import "ObjectLinker" for ObjectLinker,
EngineComunicator,
InputComunicator,
Math,
Time,
Vec3

//For each var you declare, remember to create
//		setters [varname=(v) { __varname = v }]
//		and getters [varname { __varname }]
//The construct method is mandatory, do not erase!
//The import statement at the top og the cript is mandatory, do not erase!
//Be careful not to overwrite the methods declared in Game/ScriptingAPI/ObjectLinker.wren
//[gameObject] is a reserved identifier for the engine, don't use it for your own variables

class CameraFollow is ObjectLinker{

construct new(){}

 focusTag { _focusTag }
 focusTag=(v) { _focusTag = v}

 focus { _focus }
 focus=(v) { _focus = v}
 
 offset_x {__offset_x}
 offset_x=(v){__offset_x = v}

 offset_y {__offset_y}
 offset_y =(v){__offset_y = v}

 offset_z {__offset_z}
 offset_z =(v){__offset_z = v}

 maxSpeed {__maxSpeed}
 maxSpeed =(v){__maxSpeed = v}




 Start() {
 focus = EngineComunicator.FindGameObjectsByTag(focusTag)[0]

 //Set Pos
 var focuspos = focus.getPos("global")
 setPos(focuspos.x + offset_x, focuspos.y + offset_y, focuspos.z + offset_z)

  lookAt(focuspos.x, focuspos.y, focuspos.z)

}

 Update() {

 if(focus == null){
   EngineComunicator.consoleOutput("Focus not found")
 }

 var focuspos = focus.getPos("global")
 var pos = getPos("global")


 //setPos(focuspos.x + offset_x, focuspos.y + offset_y, focuspos.z + offset_z)



 var dir = Vec3.zero()
 dir.x = (focuspos.x + offset_x) - pos.x
 dir.y = (focuspos.y + offset_y) - pos.y
 dir.z = (focuspos.z + offset_z) - pos.z

 dir.x = Math.clamp(dir.x, -maxSpeed * Time.C_GetDeltaTime(), maxSpeed * Time.C_GetDeltaTime())
 dir.y = Math.clamp(dir.y, -maxSpeed * Time.C_GetDeltaTime(), maxSpeed * Time.C_GetDeltaTime())
 dir.z = Math.clamp(dir.z, -maxSpeed * Time.C_GetDeltaTime(), maxSpeed * Time.C_GetDeltaTime())
 

 //consoleOutput(dir.x)
 //setPos(newpos.x, newpos.y, newpos.z)
 modPos(dir.x ,dir.y , dir.z)

 }
}