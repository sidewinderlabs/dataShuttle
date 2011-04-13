jQuery(document).ready(function() { 
    jQuery('.viewsresults-tab-4 a').click(function() { 
        var layer = jQuery('.openlayers-map').data('openlayers')['openlayers']; 
        layer.layers[0].onMapResize(); 
        var map = Drupal.settings.openlayers.maps['openlayers-map-auto-id-0']; 
        var center = OpenLayers.LonLat.fromString(map.center.initial.centerpoint).transform( 
                    new OpenLayers.Projection('EPSG:4326'), 
                    new OpenLayers.Projection('EPSG:' + jQuery('.openlayers-map').data('openlayers').map.projection)); 
        var zoom = parseInt(map.center.initial.zoom, 10); 
        layer.setCenter(center, zoom, false, false); 
    }); 
});
