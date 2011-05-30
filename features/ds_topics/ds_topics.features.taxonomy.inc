<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function ds_topics_taxonomy_default_vocabularies() {
  return array(
    'topics' => array(
      'name' => 'Topics',
      'description' => 'Top level ICD-10 Chapters',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '0',
      'multiple' => '0',
      'required' => '0',
      'tags' => '0',
      'module' => 'features_topics',
      'weight' => '0',
      'nodes' => array(
        'indicator' => 'indicator',
      ),
    ),
  );
}
