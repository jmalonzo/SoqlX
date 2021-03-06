// Copyright (c) 2006-2012 Simon Fell
//
// Permission is hereby granted, free of charge, to any person obtaining a 
// copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the 
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included 
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
// THE SOFTWARE.
//

#import <Cocoa/Cocoa.h>

@class ZKSforceClient;
@class ZKDescribeSObject;
@class ZKDescribeField;

@interface DescribeListDataSource : NSObject<NSOutlineViewDataSource, NSOutlineViewDelegate> {
	NSArray					*types;
	NSDictionary			*descGlobalSobjects;
	ZKSforceClient			*sforce;
	NSMutableDictionary		*describes;
	NSMutableDictionary		*operations;
	NSOperationQueue		*describeQueue;
	
	NSString				*filter;
	NSArray					*filteredTypes;
	NSOutlineView			*outlineView;
}

- (void)setSforce:(ZKSforceClient *)sf;
- (void)setTypes:(NSArray *)t view:(NSOutlineView *)ov;

// access to the desc cache
- (ZKDescribeSObject *)describe:(NSString *)type;
- (BOOL)isTypeDescribable:(NSString *)type;
- (BOOL)hasDescribe:(NSString *)type;
- (void)prioritizeDescribe:(NSString *)type;

// filter the view
- (NSString *)filter;
- (void)setFilter:(NSString *)filterValue;

// for use in a table view
- (int)numberOfRowsInTableView:(NSTableView *)v;
- (id)tableView:(NSTableView *)view objectValueForTableColumn:(NSTableColumn *)tc row:(int)rowIdx;

// for use in an outline view
- (int)outlineView:(NSOutlineView *)outlineView numberOfChildrenOfItem:(id)item;
- (BOOL)outlineView:(NSOutlineView *)outlineView isItemExpandable:(id)item;
- (id)outlineView:(NSOutlineView *)outlineView child:(int)index ofItem:(id)item;
- (id)outlineView:(NSOutlineView *)outlineView objectValueForTableColumn:(NSTableColumn *)tableColumn byItem:(id)item;

- (NSArray *)SObjects;
@end;


@interface SObjectDataSource : NSObject<NSTableViewDataSource> {
	ZKDescribeSObject	*sobject;
	NSArray				*titles;
}

- (id)initWithDescribe:(ZKDescribeSObject *)s;
// for use in a table view
- (int)numberOfRowsInTableView:(NSTableView *)v;
- (id)tableView:(NSTableView *)view objectValueForTableColumn:(NSTableColumn *)tc row:(int)rowIdx;

@end;

@interface SObjectFieldDataSource : NSObject<NSTableViewDataSource> {
	ZKDescribeField		*field;
	NSArray				*titles;
}
- (id)initWithDescribe:(ZKDescribeField *)f;
// for use in a table view
- (int)numberOfRowsInTableView:(NSTableView *)v;
- (id)tableView:(NSTableView *)view objectValueForTableColumn:(NSTableColumn *)tc row:(int)rowIdx;

@end;

@interface NoSelection : NSObject {
}
@end
