#pragma once
#include "DrawDebugHelpers.h"



#define DRAW_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 200, 30, FColor::Red, true);
#define DRAW_SPHERE_SigleFrame(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 100, 30, FColor::Red, false, -1.f)
#define DRAW_LINE(StartLocation, EndLocation) if (GetWorld()) DrawDebugLine(GetWorld(),StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 3.f);
#define DRAW_LINE_SingleFrame(Location) if (GetWorld()) DrawDebugLine(GetWorld(),StartLocation, EndLocation, FColor::Red, false, -1.f, 0, 3.f);
#define DRAW_POINT(Location) if (GetWorld()) DrawDebugPoint(GetWorld(),Location + Forward * 1000.f,15.f,FColor::Red,true,-1.f);
#define DRAW_POINT_SingleFrame(Location) if (GetWorld()) DrawDebugPoint(GetWorld(),Location + Forward * 1000.f,15.f,FColor::Red,true,-1.f);
#define DRAW_VECTOR(StartLocation,EndLocation) if (GetWorld()) \
{ \
DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, true, -1.f, 0, 3.f); \
DrawDebugPoint(GetWorld(), EndLocation, 15.f,FColor::Red,true); \
}
#define DRAW_VECTOR_SigleFrame(StartLocation,EndLocation) if (GetWorld()) \
{ \
DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, -1.f, 0, 3.f); \
DrawDebugPoint(GetWorld(), EndLocation, 15.f,FColor::Red,false,-1.f); \
}